#include "square.h"
#include "utils.h"

#include <algorithm>

namespace kakuro
{
    square::square() : value(0), deduced(true), h_cnt(0), v_cnt(0)
    {
    }

    void square::set_sum(int _h_sum, int _v_sum)
    {
        h_sum = _h_sum;
        v_sum = _v_sum;
        value= 0;
        deduced = false;
    }

    void square::deduce()
    {
        if(deduced)
            return;
        const auto h_poss_vec = utils::precomputation::possibilities[h_sum][h_cnt];
        const auto v_poss_vec = utils::precomputation::possibilities[v_sum][v_cnt];
        std::set<int> h_poss, v_poss;
        for(const auto& s: h_poss_vec)
            for(const auto ele: s)
                h_poss.insert(ele);
        for(const auto& s: v_poss_vec)
            for(const auto ele: s)
                v_poss.insert(ele);
        std::set_intersection(h_poss.begin(), h_poss.end(), v_poss.begin(), v_poss.end(),
            std::inserter(possibile_values, possibile_values.begin()));
        if(possibile_values.size() == 1)
            value = *possibile_values.begin(), deduced = true;
    }

    int square::get_value() const
    {
        return value;
    }

    std::pair<int, int> square::get_cnt() const
    {
        return {h_cnt, v_cnt};
    }

    void square::set_h_cnt(int _h_cnt)
    {
        h_cnt = _h_cnt;
    }

    void square::set_v_cnt(int _v_cnt)
    {
        v_cnt = _v_cnt;
    }

    bool square::is_deduced() const
    {
        return deduced;
    }

    bool square::is_block() const
    {
        return value == 0 && deduced;
    }
}
