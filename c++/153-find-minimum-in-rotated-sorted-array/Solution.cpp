#include <iostream>
#include <vector>
#include "../utils/ListNode.h"
#include "../utils/PrettyPrint.h"

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }

        int left = 0;
        int right = nums.size()-1;
        while (left != right) {
            int middle = (right + left + 1) / 2;
            if (middle == right) {
                break;
            }

            if (nums[middle] > nums[right]) {
                left = middle;
            } else {
                right = middle;
            }
        }

        return min(nums[left], nums[right]);
    }
};