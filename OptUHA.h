//
// Created by Simple Prosper on 16/12/2021.
//

#ifndef WOA_OPTUHA_H
#define WOA_OPTUHA_H
#include <vector>
#include <random>
#include "iostream"
#include <ctime>
typedef std::vector<double> solution;

class OptUHA {
protected:
    ///Variables
    int	pop_size = 30; // taille de la population
    int	dimension = 30; // dimension du problème
    int max_iteration = 30; //Maximum d'itération
    double epsilon = pow(10, -16);
    std::vector<double> d_fitness;//tableau qui stocke les fitness des individus
    std::vector<double> d_bestIndividu;

    ///Méthodes et fonctions
    virtual void GenerateRandomPop(int func_num) = 0;   //On n'a pas de données précises ici pour pouvoir générer la population.
    virtual solution GenerateNewSolution(int func_num, int current_ind_idx) = 0;    //Généner une nouvelle solution
    virtual solution create_new_individual(int func_num) = 0;   //Créer un nouvel individu

    double generate_random_double();    //Généner un réel aléatoirement
    int generate_random_int(int from, int to);  //Généner un entier aléatoirement

    void print_solution(const std::vector<double>& solution, double fitness) const;   //Afficher la solution avec sa fitness
    double moyenne() const;
    double ecartType(double moyenne) const;
    virtual void check_bound_pop(int func_num) = 0;    //Ramène les valeurs des individus à borne min si inférieure où a borne max si supérieure
public:
    OptUHA();   //Constructeur
    ~OptUHA() = default;    //Destructeur par défaut
};

#endif //WOA_OPTUHA_H
