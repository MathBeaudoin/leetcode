//
// https://leetcode.com/problems/longest-consecutive-sequence/description/?source=submission-ac
//
#include <vector>
#include <unordered_set>
#include <iostream>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        if (nums.size() == 1) {
            return 1;
        }

        int highest_consecutive_elements_streak = 0;

        unordered_set<int> our_set(nums.begin(), nums.end());

        for (int num : our_set) {
            if (our_set.find(num - 1) != our_set.end()) {
                continue;
            }

            int current_consecutive_elements_streak = 1;
            int current_num = num;
            while (our_set.find(++current_num) != our_set.end()) {
                ++current_consecutive_elements_streak;
            }

            if (current_consecutive_elements_streak > highest_consecutive_elements_streak) {
                highest_consecutive_elements_streak = current_consecutive_elements_streak;
            }

            if (current_consecutive_elements_streak == our_set.size()) {
                break;
            }
        }

        return highest_consecutive_elements_streak;
    }
};