#include "utils.h"

#include <iostream>
#include <algorithm>
#include <iterator>

int main(int argc, char **argv)
{
    utils::precomputation::precompute();
    for(int i = 1; i <= 45; i++)
    {
        for(int j = 1; j <= 9; j++)
        {
            const auto& poss = utils::precomputation::possibilities[i][j];
            if(poss.size() == 0)
                continue;
            std::cout << i << ' ' << j << std::endl;
            for(const auto& pos: poss)
            {
                std::copy(pos.begin(), pos.end(),
                          std::ostream_iterator<int>(std::cout, " "));
                std::cout << std::endl;
            }
            std::cout << std::endl;
        }
        std::cout << std::endl << std::endl;
    }
    return 0;
}
