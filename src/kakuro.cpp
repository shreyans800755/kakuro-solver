#include "kakuro.h"

namespace kakuro
{
    void Kakuro::initialize(std::istream& in)
    {
        for(int i = 0; i < constants::MAX_ROWS; i++)
            for(int j = 0; j < constants::MAX_ROWS; j++)
            {
                int h_sum, v_sum;
                in >> h_sum >> v_sum;
                if(h_sum > 0)
                    grid[i][j].set_sum(h_sum, v_sum);
            }
    }

    void Kakuro::print(std::ostream& out)
    {
        for(int i = 0; i < constants::MAX_ROWS; i++)
        {
            for(int j = 0; j < constants::MAX_ROWS; j++)
                out << grid[i][j].get_value() << ' ';
            out << "\n";
        }
        out << std::flush;
    }
}
