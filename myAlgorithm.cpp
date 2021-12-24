//
// Created by Simple Prosper on 16/12/2021.
//

#include "myAlgorithm.h"
#include <vector>
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
    d_fitness.reserve(pop_size);
    for(int i=0; i < pop_size; i++)
    {
        d_fitness.push_back(d_function[func_num]->fitness(population[i]));
    }
}

double myAlgorithm::evaluate_individual(int func_num, const vector<double>& ind)
{
    return d_function[func_num]->fitness(ind);
}

void myAlgorithm::update_fitness(int idx, double fitness_val)
{
    d_fitness[idx] = fitness_val;
}

double myAlgorithm::solve(int func_num)
{
    srand((unsigned int) time(nullptr));
    //Initialiser la population pour n(popsize) agents.[Xi(i=1,2,3,...n)]
    GenerateRandomPop(func_num);
    /*
    int iter = 0;
    while (iter < total_func_evals)
    {
        //Initialiser A, C, L, and p.
        double C = 2 * (double) rand();
        double A = (2 - 2*iter) / total_func_evals;
        evaluate_pop(func_num);
        double fitness = 0.0;
        solution xbest = FindBestSolution(func_num, fitness);
    }
     */
    return 0;
}

void myAlgorithm::creerFonction()
{
    d_function.push_back(make_unique<Sphere>());
    d_function.push_back(make_unique<Rastrigin>());
    d_function.push_back(make_unique<Rosenbrock>());
    d_function.push_back(make_unique<Griewank>());
}

void myAlgorithm::GenerateRandomPop(int func_num)
{
    srand((unsigned int) time(nullptr));
    for (int i = 0; i < pop_size; i++)
    {
        vector<double> individu;
        individu.reserve(dimension);
        for (int j = 0; j < dimension; j++)
        {
            individu.push_back((((double) rand() / (RAND_MAX)) * (d_function[func_num]->bound_max() - d_function[func_num]->bound_min())) + d_function[func_num]->bound_min());
        }
        population.push_back(individu);
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

void myAlgorithm::afficherFunction(int func_num)
{
    std::cout<<"x E [ "<<d_function[func_num]->bound_min()<<" ; "<<d_function[func_num]->bound_max()<<" ]"<<std::endl;
    //std::cout<<"f_bias : "<<d_function[func_num]->f_bias()<<std::endl;
    //std::cout<<"Dimension : "<<d_function[func_num]->getDimension()<<std::endl;
}

solution myAlgorithm::GenerateNewSolution(int func_num, int current_ind_idx)
{
    solution sol = create_new_individual(func_num);
    population[current_ind_idx] = sol;
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
    vector<double> individu;
    double fitness;
    int choix = menu();
    while (choix != 5)
    {
        switch(choix)
        {
            case 1:
                afficherFunction(0);
                individu = create_new_individual(0);
                fitness = evaluate_individual(0, individu);
                break;
            case 2:
                afficherFunction(1);
                individu = create_new_individual(1);
                fitness = evaluate_individual(1, individu);
                break;
            case 3:
                afficherFunction(2);
                individu = create_new_individual(2);
                fitness = evaluate_individual(2, individu);
                break;
            case 4:
                afficherFunction(3);
                individu = create_new_individual(3);
                fitness = evaluate_individual(3, individu);
                break;
            default:
                break;
        }
        print_solution(individu, fitness);
        choix = menu();
    }
}

