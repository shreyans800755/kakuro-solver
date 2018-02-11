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
        void deduce();

        int get_value() const;
        std::pair<int, int> get_cnt() const;
        void set_h_cnt(int h_cnt);
        void set_v_cnt(int v_cnt);
        bool is_deduced() const;
        bool is_block() const;

    private:
        int value;
        int h_sum, v_sum;
        int h_cnt, v_cnt;
        bool deduced;
        std::set<int> possibile_values;
    };
}

#endif
