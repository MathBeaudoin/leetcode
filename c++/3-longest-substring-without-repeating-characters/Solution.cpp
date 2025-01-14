#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> our_set = {};
        int longest_substring = 0;

        int current_substring = 0;
        for (unsigned int i = 0; i < s.size(); ++i) {
            for (unsigned int j = i; j < s.size(); ++j) {
                int old_set_size = our_set.size();
                our_set.insert(s[j]);
                int new_set_size = our_set.size();

                if (current_substring > longest_substring) {
                    longest_substring = current_substring;
                }

                if (old_set_size == new_set_size) {
                    our_set.clear();
                    current_substring = 1;
                    break;
                }

                ++current_substring;
            }

            longest_substring = max(longest_substring, current_substring);
            current_substring = 0;
        }

        return longest_substring;
    }
};

