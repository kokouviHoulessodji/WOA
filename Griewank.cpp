//
// Created by Simple Prosper on 22/12/2021.
//

#include "Griewank.h"

Griewank::Griewank(int borne_min, int borne_max, int f_bias) :
        d_borne_min{borne_min}, d_borne_max{borne_max}, d_f_bias{f_bias}
{

}
double Griewank::fitness(const std::vector<double> &x)
{
    double somme = 0.0;
    double prod = 1.0;

    for (int i = 0; i < dimension; i++)
    {
        somme += pow(x[i], 2) / 4000.0;
        prod *= cos(x[i] / sqrt(i+1)) + 1.0;
    }
    return somme - prod + f_bias();
}
int Griewank::bound_min() const {
    return d_borne_min;
}
int Griewank::bound_max() const {
    return d_borne_max;
}

int Griewank::f_bias() const {
    return d_f_bias;
}
