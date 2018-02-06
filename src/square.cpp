#include "square.h"

namespace kakuro
{
    square::square() : value(0), deduced(true)
    {
    }

    void square::set_sum(int _h_sum, int _v_sum)
    {
        h_sum = _h_sum;
        v_sum = _v_sum;
        value= 0;
        deduced = false;
    }

    int square::get_value()
    {
        return value;
    }
}
