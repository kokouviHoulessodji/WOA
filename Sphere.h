//
// Created by Simple Prosper on 22/12/2021.
//

#ifndef WOA_SPHERE_H
#define WOA_SPHERE_H
#include "objective_func.h"

class Sphere : public objective_func {
public:
    explicit Sphere(int borne_min = -100, int borne_max = 100, int f_bias = -450);
    double fitness(const std::vector<double>& x) override;
    int bound_min() const override;
    int bound_max() const override;
    int f_bias() const override;
private:
    int d_borne_min;
    int d_borne_max;
    int d_f_bias;
};


#endif //WOA_SPHERE_H
