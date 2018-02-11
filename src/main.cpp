#include "kakuro.h"
#include "utils.h"

#include <iostream>
#include <algorithm>
#include <iterator>

namespace constants = kakuro::constants;
namespace utils = kakuro::utils;

std::vector<std::set<int>>
    utils::precomputation::possibilities[utils::max_sum(9) + 1][constants::MAX_ROWS + 1];

int main(int argc, char **argv)
{
    kakuro::utils::precomputation::precompute();
    kakuro::Kakuro kakuroObj;
    kakuroObj.initialize(std::cin);
    kakuroObj.solve();
    kakuroObj.print(std::cout);
    return 0;
}
