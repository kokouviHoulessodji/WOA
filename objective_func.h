//
// Created by Simple Prosper on 16/12/2021.
//

#ifndef WOA_OBJECTIVE_FUNC_H
#define WOA_OBJECTIVE_FUNC_H
#include<iostream>
#include<cmath>
#include <vector>

class objective_func {
public:
    objective_func(int borne_min, int borne_max, int f_bias);
    virtual double fitness(const std::vector<double>& x) = 0;   //Evaluer la fonction en fonction de l'individu passé en paramètre
    virtual ~objective_func() = default;    //Destructeur virtuel
    int bound_min() const;  //Renvoyer la borne min
    int bound_max() const;  //Renvoyer la borne max
    int f_bias() const; //Renvoyer le f_bias
protected:
    int d_borne_min;
    int d_borne_max;
    int d_f_bias;
};


#endif //WOA_OBJECTIVE_FUNC_H
