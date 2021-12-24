//
// Created by Simple Prosper on 16/12/2021.
//

#include "OptUHA.h"
#include<iostream>
#include<random>

OptUHA::OptUHA()
{

}

double OptUHA::generate_random_double()
{
    srand(time(nullptr));
    return (double)rand() / RAND_MAX;
}

int OptUHA::generate_random_int(int from, int to)
{
    srand(time(nullptr));
    return rand()%to + from;
}

void OptUHA::print_solution(const std::vector<double>& solution, double fitness)
{
    std::cout<<"[ ";
    for(int i = 0; i < dimension; i++)
    {
        std::cout<<solution[i]<<" ";
    }
    std::cout<<"]";
    std::cout<<" de fitness "<<fitness;
    std::cout<<std::endl;
}

void OptUHA::check_bound_pop(std::vector<solution> &population) {

}
