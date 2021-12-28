//
// Created by Simple Prosper on 22/12/2021.
//

#ifndef WOA_GRIEWANK_H
#define WOA_GRIEWANK_H
#include "objective_func.h"

class Griewank : public objective_func{
public:
    explicit Griewank(int borne_min = -600, int borne_max = 600, int f_bias = -180);
    double fitness(const std::vector<double>& x) override;
    int bound_min() const override;
    int bound_max() const override;
    int f_bias() const override;
private:
    int d_borne_min;
    int d_borne_max;
    int d_f_bias;
};


#endif //WOA_GRIEWANK_H
