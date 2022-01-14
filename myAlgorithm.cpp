//
// Created by Simple Prosper on 16/12/2021.
//

#include "myAlgorithm.h"
#include <vector>
#include <cmath>
#include "Sphere.h"
#include "Rastrigin.h"
#include "Rosenbrock.h"
#include "Griewank.h"
myAlgorithm::myAlgorithm() : population{}, d_function{}
{
    creerFonction();
}

void myAlgorithm::UpdatePopulation(int idx, solution new_sol)
{
    population[idx] = std::move(new_sol);
}

vector<double> myAlgorithm::FindBestSolution(double& fitness)
{
    int idx = 0;
    fitness = d_fitness[0];
    for(int i=1; i < d_fitness.size(); i++)
    {
        if(fitness > d_fitness[i])
        {
            fitness = d_fitness[i];
            idx = i;
        }
    }
    return population[idx];
}

void myAlgorithm::evaluate_pop(int func_num)
{
    d_fitness.resize(pop_size);
    for (int i = 0; i < pop_size; i++)
        update_fitness(i, evaluate_individual(func_num, population[i]));
    /*
     * for (int i = 0; i < pop_size; i++)
     *      d_fitness[i] = d_function[func_num]->fitness(population[i]);
     */
}

double myAlgorithm::evaluate_individual(int func_num, const vector<double>& ind)
{
    return d_function[func_num]->fitness(ind);
}

void myAlgorithm::update_fitness(int idx, double fitness_val)
{
    d_fitness[idx] = fitness_val;
}

void myAlgorithm::solve(int func_num)
{
    GenerateRandomPop(func_num);
    std::cout<<"------------Population initiale----------"<<std::endl;
    afficherPopulation(func_num);
    std::cout<<"------------------------------------------"<<std::endl;
    evaluate_pop(func_num);
    d_bestIndividu.reserve(pop_size);
    int nb = 1;
    double fitness = 0.0;
    vector<double> bestSolution(dimension);
    bestSolution = FindBestSolution(fitness);
    d_bestIndividu.push_back(fitness);
    for (int iter = 1; iter < max_iteration; iter++)
    {
        //Update position
        for(int i = 0; i < pop_size; i++)
        {
            double a = 2.0 - (double)iter * (2.0 / max_iteration);
            //double a2 = -1.0 + (double)iter * (-1.0 / max_iteration);
            double rnd1 = generate_random_double();
            double rnd2 = generate_random_double();
            double A  = 2.0 * a * rnd1 - a;
            double c = 2.0 * rnd2;
            double b = 1.0;
            double l = (a - 1.0) * generate_random_double() + 1.0;
            double p = generate_random_double();
            for(int j = 0; j < dimension; j++)
            {
                if (p < 0.5)
                {
                    if (abs(A) < 1)
                    {
                        double D = abs(c*bestSolution[j] - population[i][j]) ;
                        population[i][j] = bestSolution[j] - A*D;
                    }
                    else
                    {
                        int rI = generate_random_int(0, pop_size - 1);
                        double D = abs(c*population[rI][j] - population[i][j]);
                        population[i][j] = population[rI][j] - A*D;
                    }
                }
                else
                {
                    double D = abs(bestSolution[j] - population[i][j]);
                    population[i][j] = D * exp(b * l) * cos(l * 2 * M_PI) + bestSolution[j];
                }
            }
        }
        check_bound_pop(func_num);
        std::cout<<"------------Iteration "<<iter<<"----------"<<std::endl;
        afficherPopulation(func_num);
        std::cout<<"------------------------------------------"<<std::endl;
        evaluate_pop(func_num);
        nb++;
        bestSolution = FindBestSolution(fitness);
        d_bestIndividu.push_back(fitness);
    }
    double ecartT = ecartType(moyenne());
    cout<<"Sur "<<max_iteration<<" exécutions,"<<std::endl<<"La moyenne est : "<<moyenne()<<std::endl<<"L'écart type est : "<<ecartT<<endl;
    print_solution(bestSolution, fitness);
    std::cout<<"Nombre d'appel de la fonction objectif : "<<nb<<std::endl;
}

void myAlgorithm::creerFonction()
{
    d_function.push_back(make_unique<Sphere>(-100, 100, -450));
    d_function.push_back(make_unique<Rastrigin>(-5, 5, -330));
    d_function.push_back(make_unique<Rosenbrock>(-100, 100, 390));
    d_function.push_back(make_unique<Griewank>(-600, 600, -180));
}

void myAlgorithm::GenerateRandomPop(int func_num)
{
    population.resize(pop_size);
    for (int i = 0; i < pop_size; i++)
    {
        vector<double> individu;
        individu.reserve(dimension);
        for (int j = 0; j < dimension; j++)
            individu.push_back((((double) rand() / (RAND_MAX)) * (d_function[func_num]->bound_max() - d_function[func_num]->bound_min())) + d_function[func_num]->bound_min());
        population[i] = (individu);
    }
}

solution myAlgorithm::create_new_individual(int func_num)
{
    vector<double> individu;
    individu.reserve(dimension);
    for (int j = 0; j < dimension; j++)
    {
        individu.push_back((((double) rand() / (RAND_MAX)) * (d_function[func_num]->bound_max() - d_function[func_num]->bound_min())) + d_function[func_num]->bound_min());
    }
    return individu;
}


solution myAlgorithm::GenerateNewSolution(int func_num, int current_ind_idx)
{
    solution sol = create_new_individual(func_num);
    //population[current_ind_idx] = sol;
    UpdatePopulation(current_ind_idx, sol);
    return sol;
}

int myAlgorithm::menu()
{
    int choix;
    do
    {
        cout<<"Sur quelle fonction voulez-vous appliqué l'algorithme? \n";
        cout<<" 1 - 2D Shifted Sphere's function\n";
        cout<<" 2 - 2D Shifted Rastrigin's function\n";
        cout<<" 3 - 2D Shifted Rosenbrock's function\n";
        cout<<" 4 - 2D Shifted Griewank's function\n";
        cout<<" 5 - Quitter\n";
        cout<<" votre choix : ";
        cin>>choix;
    } while (choix<1 || choix>5);
    return choix;
}

void myAlgorithm::run()
{
    srand(time(nullptr));
    int choix = menu();
    while (choix != 5)
    {
        switch(choix)
        {
            case 1: solve(0); cout<<endl;
                break;
            case 2: solve(1); cout<<endl;
                break;
            case 3: solve(2); cout<<endl;
                break;
            case 4: solve(3); cout<<endl;
                break;
            default: std::cerr<<" Cette fonction n'existe pas, veuillez rentrer un identifiant correct merci"<<endl;
                break;
        }
        choix = menu();
    }
}

void myAlgorithm::check_bound_pop(int func_num)
{
    for(int i = 0; i < pop_size; i++)
    {
        for(int j = 0; j < dimension; j++)
        {
            if(population[i][j] < d_function[func_num]->bound_min())
                population[i][j] = d_function[func_num]->bound_min();
            else if(population[i][j] > d_function[func_num]->bound_max())
                population[i][j] = d_function[func_num]->bound_max();
        }
    }
}

void myAlgorithm::afficherPopulation(int func_num)
{
    for (int i = 0; i < pop_size; i++)
    {
        cout<<"[ ";
        for (int j = 0; j < dimension; j++)
        {
            cout<<population[i][j]<<"; ";
        }
        cout<<" ] de fitness : "<<evaluate_individual(func_num, population[i]);
        cout<<endl;
    }
}
/*
void myAlgorithm::updatePosition(double a, double a2, vector<double> &bestSolution)
{
    for(int i = 0; i < pop_size; i++)
    {
        double rnd1 = generate_random_double();
        double rnd2 = generate_random_double();
        double A  = 2.0 * a * rnd1 - a;
        double c = 2.0 * rnd2;
        double b = 1.0;
        double l = (a2 - 1.0) * generate_random_double() + 1.0;
        double p = generate_random_double();
        for(int j = 0; j < dimension; j++)
        {
            if (p < 0.5)
            {
                if (abs(A) < 1)
                {
                    double D = abs(c*(bestSolution[j]) - population[i][j]) ;
                    population[i][j] = bestSolution[j] - A*D;
                }
                else
                {
                    int rI = generate_random_int(0, pop_size - 1);
                    double D = abs(c*population[rI][j] - population[i][j]);
                    population[i][j] = population[rI][j] - A*D;
                }
            }
            else
            {
                double D = abs(bestSolution[j] - population[i][j]);
                population[i][j] = D * exp(b * l) * cos(l * 2 * M_PI) + bestSolution[j];
            }
        }
    }
}
*/