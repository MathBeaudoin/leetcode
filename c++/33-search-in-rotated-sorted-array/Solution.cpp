#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 1) {
            return nums[0] == target ? 0 : -1;
        }

        int min_index = find_min_index(nums);
        vector<int> nums_copy(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            nums_copy[i] = nums[(i + min_index) % nums.size()];
        }

        int left = 0;
        int right = nums_copy.size() - 1;
        while (left != right) {
            int middle = (right + left + 1) / 2;
            if (middle == right) {
                break;
            }

            if (target < nums_copy[middle]) {
                right = middle;
            } else {
                left = middle;
            }
        }

        if (nums_copy[left] == target) {
            return (left + min_index) % nums_copy.size();
        } else if (nums_copy[right] == target) {
            return (right + min_index) % nums_copy.size();
        }

        return -1;
    }

private:
    int find_min_index(vector<int>& nums) {
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

        return nums[left] > nums[right] ? right : left;
    }
};