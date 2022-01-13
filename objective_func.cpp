#include "objective_func.h"

objective_func::objective_func(int borne_min, int borne_max, int f_bias) : d_borne_min{borne_min}, d_borne_max{borne_max}, d_f_bias{f_bias}
{

}
int objective_func::bound_min() const {
    return d_borne_min;
}
int objective_func::bound_max() const {
    return d_borne_max;
}

int objective_func::f_bias() const {
    return d_f_bias;
}


