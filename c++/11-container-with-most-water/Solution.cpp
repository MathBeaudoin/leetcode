#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area = 0;

        int left_pointer = 0;
        int right_pointer = height.size() - 1;
        while (left_pointer != right_pointer) {
            int area = min(height[left_pointer], height[right_pointer]) * (right_pointer - left_pointer);
            max_area = max(max_area, area);

            if (height[left_pointer] >= height[right_pointer]) {
                --right_pointer;
            } else {
                ++left_pointer;
            }
        }

        return max_area;
    }
};