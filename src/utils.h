#ifndef UTILS_H
#define UTILS_H

#include "constants.h"

#include <vector>
#include <set>

namespace kakuro::utils
{
    constexpr int max_sum(int squares)
    {
        return squares * (squares + 1) / 2;
    }

    namespace precomputation
    {
        extern std::vector<std::set<int>>
            possibilities[max_sum(9) + 1][constants::MAX_ROWS + 1];

        static void precompute();
        static std::vector<std::set<int>> sum_split(int sum, int splits);
        static void sum_split_util(std::vector<std::set<int>>& result,
                            int sum, int cur_sum,
                            int splits, int cur_splits,
                            std::set<int>& s, int min=0);

        void precompute()
        {
            const int max_value = max_sum(9);
            for(int sum = 1; sum <= max_value; sum++)
            {
                for(int splits = 1; splits <= constants::MAX_ROWS; splits++)
                {
                    int min_poss_sum = max_sum(splits);
                    int max_poss_sum = max_sum(9) - max_sum(9 - splits);
                    if(sum < min_poss_sum)
                        break;
                    if(sum > max_poss_sum)
                        continue;

                    possibilities[sum][splits] = sum_split(sum, splits);
                }
            }
        }

        std::vector<std::set<int>> sum_split(int sum, int splits)
        {
            std::vector<std::set<int>> result;
            std::set<int> s;
            sum_split_util(result, sum, 0, splits, 0, s);
            return result;
        }

        void sum_split_util(std::vector<std::set<int>>& result,
                            int sum, int cur_sum,
                            int splits, int cur_splits,
                            std::set<int>& s, int min)
        {
            if(min == 9 || cur_sum > sum)
                return;

            if(cur_splits == splits - 1)
            {
                if((sum - cur_sum) > min && (sum - cur_sum) < 10)
                {
                    s.insert(sum - cur_sum);
                    result.push_back(s);
                    s.erase(sum - cur_sum);
                }
                return;
            }

            for(int offset = 1; min + offset < 10; offset++)
            {
                s.insert(min + offset);
                sum_split_util(result, sum, cur_sum + min + offset, splits,
                               cur_splits + 1, s, min + offset);
                s.erase(min + 1);
            }
        }
    }
}

#endif
