//
// Created by Simple Prosper on 22/12/2021.
//

#ifndef WOA_SPHERE_H
#define WOA_SPHERE_H
#include "objective_func.h"

class Sphere : public objective_func {
public:
    Sphere(int borne_min, int borne_max, int f_bias);
    double fitness(const std::vector<double>& x) override;
};


#endif //WOA_SPHERE_H
