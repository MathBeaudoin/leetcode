#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> possible_reconstructions {s};

        while (true) {
            if (possible_reconstructions.empty()) {
                return false;
            }

            unordered_set<string> new_reconstructions;
            for (const string& possible_reconstruction : possible_reconstructions) {
                for (const string& word : wordDict) {
                    string possible_reconstruction_substring = possible_reconstruction.substr(0, word.size());
                    if (possible_reconstruction_substring.empty()) {
                        return true;
                    }

                    if (possible_reconstruction_substring == word) {
                        new_reconstructions.insert(possible_reconstruction.substr(word.size()));
                    }
                }
            }

            possible_reconstructions = new_reconstructions;
        }
    }
};
