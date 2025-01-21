#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int total_sum = nums.size() * (nums.size() + 1) / 2;
        for (const int& num : nums) {
            total_sum -= num;
        }

        return total_sum;
    }
};