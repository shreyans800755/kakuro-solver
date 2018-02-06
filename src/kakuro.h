#ifndef KAKURO_H
#define KAKURO_H

#include "constants.h"
#include "square.h"

#include <iostream>

namespace kakuro
{
    class Kakuro
    {
    public:
        Kakuro() = default;
        void initialize(std::istream&);
        void print(std::ostream&);
    private:
        square grid[constants::MAX_ROWS][constants::MAX_ROWS];
    };
}

#endif
