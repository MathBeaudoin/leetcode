#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;

        for (int i = 0; i < s.size(); ++i) {
            int even_count = count_palindroms_in_substring(s, i, i + 1);
            int odd_count = count_palindroms_in_substring(s, i, i);
            count += even_count + odd_count;
        }

        return count;
    }

private:
    int count_palindroms_in_substring(string s, int left_pointer, int right_pointer) {
        int count = 0;

        while (left_pointer >= 0 && right_pointer < s.size()) {
            if (s[left_pointer] != s[right_pointer]) {
                break;
            }

            ++count;
            --left_pointer;
            ++right_pointer;
        }

        return count;
    }
};