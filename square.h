#ifndef SQUARE_H
#define SQUARE_H

#include <set>

class square
{
public:
    square() = delete;
    square(int h_sum, int v_sum, bool value_allowed=true);

private:
    void compute_possible_values();

    int value;
    int h_sum, v_sum;
    bool deduced;
    std::set<int> possibile_values;
};

#endif
