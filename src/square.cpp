#include "square.h"

namespace kakuro
{
    square::square(int _h_sum, int _v_sum, bool value_allowed) :
        h_sum(_h_sum), v_sum(_v_sum)
    {
        if(value_allowed)
        {
            this->value = 0;
            this->deduced = false;
        }
        else
        {
            this->value = -1;
        }
    }
}
