#ifndef SQUARE_H
#define SQUARE_H

#include <set>

namespace kakuro
{
    class square
    {
    public:
        square();
        void set_sum(int h_sum, int v_sum);
        int get_value();

    private:
        int value;
        int h_sum, v_sum;
        bool deduced;
        std::set<int> possibile_values;
    };
}

#endif
