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
    return (double)rand() / RAND_MAX;
}

int OptUHA::generate_random_int(int from, int to)
{
    return rand()%to + from;
}

void OptUHA::print_solution(const std::vector<double>& solution, double fitness)  const
{
    std::cout<<"Best solution [ ";
    for(int i = 0; i < dimension; i++)
    {
        std::cout<<solution[i]<<" ";
    }
    std::cout<<"]"<<std::endl;
    std::cout<<" obj_val : "<<fitness;
    std::cout<<std::endl;
}

