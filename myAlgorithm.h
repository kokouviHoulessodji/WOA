//
// Created by Simple Prosper on 16/12/2021.
//

#ifndef WOA_MYALGORITHM_H
#define WOA_MYALGORITHM_H
#include "OptUHA.h"
#include "objective_func.h"
#include<memory>
using std::endl;
using std::cout;
using std::cin;
using std::vector;
using std::unique_ptr;
using std::make_unique;

class myAlgorithm : public OptUHA {
protected:
    ///Les variables
    vector<unique_ptr<objective_func>> d_function;   //tableau de pointeurs intelligents pour stocker les fonctions du benchmark
    vector<solution> population;    //vecteur de 2 dimension pour stocker la population

    ///Les méthodes et fonctions
    virtual void GenerateRandomPop(int func_num) override;  //Générer la population aléatoirement en fonction des bornes correspondantes à la fonction "func_num"
    virtual solution create_new_individual(int func_num) override;  //Créer un nouvel individu
    virtual solution GenerateNewSolution(int func_num, int current_ind_idx) override;   //Généner une nouvelle solution

    void UpdatePopulation(int idx, solution new_sol);    //Remplacer un individu de la population par un nouvel
    vector<double> FindBestSolution(double &fitness);   //Trouver la meilleure solution dans la population
    void evaluate_pop(int func_num);    //Evaluer la population en fonction du numéro de la fonction qui est passée en paramètre
    double evaluate_individual(int func_num, const vector<double>& ind);    //Evaluer un individu en fonction du numéro de la fonction qui est passée en paramètre
    void update_fitness(int idx, double fitness_val);   //Mettre à jour la fitness de l'individu "idx" avec la valeur "fitness_val"

    void creerFonction();   //Remplir le tableau de fonction par les fonctions du benchmark
    void afficherFunction(int func_num);//Pour tester
    double solve(int func_num);
public:
    myAlgorithm();  // mettre un constructeur avec des paramètres ici
    ~myAlgorithm() = default; //Destructeur par défaut
    static int menu(); //Switch qui demande à l'utilisateur sur quelle fonction il veut appliquer l'algorithme
    void run(); //Lancer l'algorithme en fonction du choix qu'il a fait dans la fonction "menu"
};


#endif //WOA_MYALGORITHM_H
