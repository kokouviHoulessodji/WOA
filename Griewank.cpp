//
// Created by Simple Prosper on 22/12/2021.
//

#include "Griewank.h"

Griewank::Griewank(int borne_min, int borne_max, int f_bias) : objective_func{borne_min, borne_max, f_bias}
{

}
double Griewank::fitness(const std::vector<double> &x)
{
    double somme = 0.0;
    double prod = 1.0;

    for (int i = 0; i < x.size(); i++)
    {
        somme += pow(x[i], 2) / 4000.0;
        prod *= cos(x[i] / sqrt(i+1)) + 1.0;
    }
    return somme - prod + f_bias();
}
