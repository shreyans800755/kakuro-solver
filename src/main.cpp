#include "kakuro.h"
#include "utils.h"

#include <iostream>
#include <algorithm>
#include <iterator>

int main(int argc, char **argv)
{
    kakuro::utils::precomputation::precompute();
    kakuro::Kakuro kakuroObj;
    kakuroObj.initialize(std::cin);
    // TODO: solve Kakuro
    kakuroObj.print(std::cout);
    return 0;
}
