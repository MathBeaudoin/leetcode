#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> triplets;
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            if (i != 0 && nums[i] == nums[i-1]) {
                continue;
            }

            int first_val = nums[i];
            int left_pointer = i + 1;
            int right_pointer = n - 1;
            while (left_pointer < right_pointer) {
                int left_pointer_val = nums[left_pointer];
                int right_pointer_val = nums[right_pointer];
                if (left_pointer_val + right_pointer_val + first_val == 0) {
                    triplets.push_back({first_val, left_pointer_val, right_pointer_val});
                    while (left_pointer < right_pointer && left_pointer_val == nums[left_pointer+1]) {
                        ++left_pointer;
                    }

                    while (left_pointer < right_pointer && right_pointer_val == nums[right_pointer-1]) {
                        --right_pointer;
                    }

                    --right_pointer;
                    ++left_pointer;
                } else if (left_pointer_val + right_pointer_val + first_val > 0) {
                    --right_pointer;
                } else {
                    ++left_pointer;
                }
            }
        }

        return triplets;
    }
};