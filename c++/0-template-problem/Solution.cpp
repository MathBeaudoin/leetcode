#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> parentheses_stack;

        for (const char& c : s) {
            if (is_opening_char(c)) {
                parentheses_stack.push(c);
            }
            else if (is_closing_char(c)) {
                if (parentheses_stack.empty()) {
                    return false;
                }

                char last_char = parentheses_stack.top();
                parentheses_stack.pop();

                if (!opening_mapped_to_closing(last_char, c)) {
                    return false;
                }
            }
        }

        return parentheses_stack.empty();
    }

private:
    bool is_closing_char(const char& c) {
        return c == ')' || c == ']' || c == '}';
    }

    bool is_opening_char(const char& c) {
        return c == '(' || c == '[' || c == '{';
    }

    bool opening_mapped_to_closing(const char& opening, const char& closing) {
        if (opening == '(') {
            return closing == ')';
        }
        else if (opening == '[') {
            return closing == ']';
        }
        else {
            return closing == '}';
        }
    }
};