//
// Created by Simple Prosper on 22/12/2021.
//

#include "Rosenbrock.h"

Rosenbrock::Rosenbrock(int borne_min, int borne_max, int f_bias) :
    d_borne_min{borne_min}, d_borne_max{borne_max}, d_f_bias{f_bias}
{

}
double Rosenbrock::fitness(const std::vector<double> &x)
{
    int somme= 0;

    for (int i=1; i<= dimension-1; i++)
    {
        somme+=(100*pow((pow(x[i],2)-x[i+1]),2)+pow((x[i]-1),2));
    }
    return somme + d_f_bias;
}

int Rosenbrock::bound_min() const {
    return d_borne_min;
}

int Rosenbrock::bound_max() const {
    return d_borne_max;
}

int Rosenbrock::f_bias() const {
    return d_f_bias;
}

