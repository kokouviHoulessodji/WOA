cmake_minimum_required(VERSION 3.21)
project(WOA)

set(CMAKE_CXX_STANDARD 14)

add_executable(WOA main.cpp OptUHA.cpp OptUHA.h myAlgorithm.cpp myAlgorithm.h objective_func.cpp objective_func.h Rastrigin.cpp Rastrigin.h Rosenbrock.cpp Rosenbrock.h Sphere.cpp Sphere.h Griewank.cpp Griewank.h)
