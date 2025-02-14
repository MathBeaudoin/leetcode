#include <iostream>
#include <vector>
#include "../utils/ListNode.h"
#include "../utils/PrettyPrint.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> results;
        vector<vector<int>> flow_chart = vector(m, vector<int>(n, 0));

        // 0: no data yet, 1 can visit pacific, 2 can visit atlantic, 3 both

        return results;
    }
};