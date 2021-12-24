//
// Created by Simple Prosper on 22/12/2021.
//

#ifndef WOA_RASTRIGIN_H
#define WOA_RASTRIGIN_H
#include "objective_func.h"

class Rastrigin : public objective_func {
public:
    Rastrigin(int borne_min = -5, int borne_max = 5, int f_bias = -330);
    virtual double fitness(const std::vector<double>& x) override;
    virtual int bound_min() const override;
    virtual int bound_max() const override;
    virtual int f_bias() const override;
private:
    int d_borne_min;
    int d_borne_max;
    int d_f_bias;
};


#endif //WOA_RASTRIGIN_H
