//
// Created by Simple Prosper on 22/12/2021.
//

#include "Rastrigin.h"
Rastrigin::Rastrigin(int borne_min, int borne_max, int f_bias) : objective_func{borne_min, borne_max, f_bias}
{

}
double Rastrigin::fitness(const std::vector<double> &x)
{
    double somme = 0;
    double p = M_PI;
    for (int i = 0; i < x.size(); i++)
        somme += (pow(x[i], 2) - 10.0 * cos(2 * p * x[i]) + 10);
    return somme + d_f_bias;
}
