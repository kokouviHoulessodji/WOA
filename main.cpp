#include <iostream>
#include <vector>
#include "myAlgorithm.h"
using std::cout;
using std::cin;


int main()
{
    auto myAlgo = new myAlgorithm();
    myAlgo->run();
    delete myAlgo;
}