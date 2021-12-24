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
    virtual double fitness(const std::vector<double>& x) = 0;   //Evaluer la fonction en fonction de l'individu passé en paramètre
    virtual ~objective_func() = default;    //Destructeur virtuel
    virtual int bound_min() const = 0;  //Renvoyer la borne min
    virtual int bound_max() const = 0;  //Renvoyer la borne max
    virtual int f_bias() const = 0; //Renvoyer le f_bias
    int getDimension() const;
protected:
    int dimension = 30;
};


#endif //WOA_OBJECTIVE_FUNC_H
