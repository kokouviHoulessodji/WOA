//
// Created by Simple Prosper on 22/12/2021.
//

#ifndef WOA_ROSENBROCK_H
#define WOA_ROSENBROCK_H
#include "objective_func.h"

class Rosenbrock: public objective_func {
public:
    Rosenbrock(int borne_min, int borne_max, int f_bias);
    double fitness(const std::vector<double>& x) override;
};


#endif //WOA_ROSENBROCK_H
