//
// Created by Simple Prosper on 22/12/2021.
//

#include "Sphere.h"
Sphere::Sphere(int borne_min, int borne_max, int f_bias):
        d_borne_min{borne_min}, d_borne_max{borne_max}, d_f_bias{f_bias}
{

}

double Sphere::fitness(const std::vector<double> &x)
{
    double somme = 0;
    for (int i=0; i< dimension; i++)
    {
        somme += pow(x[i],2);
    }
    return somme + d_f_bias;
}

int Sphere::bound_min() const
{
    return d_borne_min;
}

int Sphere::bound_max() const {
    return d_borne_max;
}

int Sphere::f_bias() const {
    return d_f_bias;
}
