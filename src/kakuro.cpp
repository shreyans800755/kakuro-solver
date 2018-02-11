#include "kakuro.h"
#include "utils.h"

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
        set_cnt();
    }

    void Kakuro::solve()
    {
        solve_using_intersection();
        solve_using_backtracking();
    }

    void Kakuro::print(std::ostream& out) const
    {
        for(int i = 0; i < constants::MAX_ROWS; i++)
        {
            for(int j = 0; j < constants::MAX_ROWS; j++)
                out << grid[i][j].get_value() << ' ';
            out << "\n";
        }
        out << std::flush;
    }

    void Kakuro::solve_using_intersection()
    {
        for(int i = 0; i < constants::MAX_ROWS; i++)
            for(int j = 0; j < constants::MAX_ROWS; j++)
            {
                if(grid[i][j].is_deduced())
                    continue;
                grid[i][j].deduce();
            }
    }

    void Kakuro::solve_using_backtracking()
    {

    }

    void Kakuro::set_cnt()
    {
        bool counting = false;
        int last = 0;
        for(int i = 0; i < constants::MAX_ROWS; i++)
        {
            counting = false;
            last = 0;
            for(int j = 0; j < constants::MAX_ROWS; j++)
            {
                if(not counting && grid[i][j].is_block())
                {
                    last = j + 1;
                    continue;
                }
                if(grid[i][j].is_block())
                {
                    for(int k = last; k < j; k++)
                        grid[i][k].set_h_cnt(j - last);
                    counting = false;
                    last = j + 1;
                    continue;
                }
                counting = true;
            }
            if(counting)
            {
                for(int k = last; k < constants::MAX_ROWS; k++)
                    grid[i][k].set_h_cnt(constants::MAX_ROWS - last);
            }
        }

        for(int i = 0; i < constants::MAX_ROWS; i++)
        {
            counting = false;
            last = 0;
            for(int j = 0; j < constants::MAX_ROWS; j++)
            {
                if(not counting && grid[j][i].is_block())
                {
                    last = j + 1;
                    continue;
                }
                if(grid[j][i].is_block())
                {
                    for(int k = last; k < j; k++)
                        grid[k][i].set_v_cnt(j - last);
                    counting = false;
                    last = j + 1;
                    continue;
                }
                counting = true;
            }
            if(counting)
            {
                for(int k = last; k < constants::MAX_ROWS; k++)
                    grid[k][i].set_v_cnt(constants::MAX_ROWS - last);
            }
        }
    }
}
