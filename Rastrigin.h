//
// Created by Simple Prosper on 22/12/2021.
//

#ifndef WOA_RASTRIGIN_H
#define WOA_RASTRIGIN_H
#include "objective_func.h"

class Rastrigin : public objective_func {
public:
    Rastrigin(int borne_min, int borne_max, int f_bias);
    double fitness(const std::vector<double>& x) override;
};


#endif //WOA_RASTRIGIN_H
