//
// Created by Simple Prosper on 22/12/2021.
//

#ifndef WOA_GRIEWANK_H
#define WOA_GRIEWANK_H
#include "objective_func.h"

class Griewank : public objective_func{
public:
    Griewank(int borne_min, int borne_max, int f_bias);
    double fitness(const std::vector<double>& x) override;
};


#endif //WOA_GRIEWANK_H
