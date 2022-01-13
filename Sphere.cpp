//
// Created by Simple Prosper on 22/12/2021.
//

#include "Sphere.h"


Sphere::Sphere(int borne_min, int borne_max, int f_bias) : objective_func{borne_min, borne_max, f_bias}
{

}
double Sphere::fitness(const std::vector<double> &x)
{
    double somme = 0;
    for (int i=0; i< x.size(); i++)
    {
        somme += pow(x[i],2);
    }
    return somme + f_bias();
}
