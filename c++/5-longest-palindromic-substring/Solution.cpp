#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() == 1) {
            return s;
        }

        int left = 0;
        int right = 0;

        for (unsigned int i = 0; i < s.size(); ++i) {
            int even = findLongestPalindrome(s, i - 1, i + 1);
            int odd = findLongestPalindrome(s, i, i + 1);
            int max_val = max(even, odd);

            if (max_val > right - left + 1) {
                left = i - (max_val - 1) / 2;
                right = i + max_val / 2;
            }
        }

        return s.substr(left, right - left + 1);
    }

private:
    int findLongestPalindrome(string s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            --left;
            ++right;
        }

        return right - left - 1;
    }
};