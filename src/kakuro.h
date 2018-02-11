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
        void solve();
        void print(std::ostream&) const;
    private:
        square grid[constants::MAX_ROWS][constants::MAX_ROWS];

        void solve_using_intersection();
        void solve_using_backtracking();
        void set_cnt();
    };
}

#endif
