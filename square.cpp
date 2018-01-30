#include "square.h"

square::square(int _h_sum, int _v_sum, bool value_allowed) :
    h_sum(_h_sum), v_sum(_v_sum)
{
    if(value_allowed)
    {
        this->value = 0;
        this->deduced = false;
        compute_possible_values();
    }
    else
    {
        this->value = -1;
    }
}

void square::compute_possible_values()
{
    
}
