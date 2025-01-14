#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> value_to_index;
        int first_index = 0;
        int second_index = 0;

        for (int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            int diff = target - num;

            auto potential_index_ite = value_to_index.find(diff);
            if (potential_index_ite != value_to_index.end()) {
                first_index = potential_index_ite->second;
                second_index = i;
                break;
            }

            value_to_index[num] = i;
        }

        return { first_index, second_index };
    }
};