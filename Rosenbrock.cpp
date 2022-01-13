//
// Created by Simple Prosper on 22/12/2021.
//

#include "Rosenbrock.h"
Rosenbrock::Rosenbrock(int borne_min, int borne_max, int f_bias) : objective_func{borne_min, borne_max, f_bias}
{

}
double Rosenbrock::fitness(const std::vector<double> &x)
{
    double somme = 0.0;

    for (int i=0; i< x.size()-1; i++)
    {
        somme += (100.0 * pow((pow(x[i],2) - x[i+1]),2) + pow((x[i] - 1),2));
    }
    return somme + d_f_bias;
}

