#include <iostream>
#include <vector>
#include "../utils/ListNode.h"
#include "../utils/PrettyPrint.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size();
        int columns = heights[0].size();

        vector<vector<bool>> atlantic_access(rows, vector<bool>(columns, false));
        vector<vector<bool>> pacific_access(rows, vector<bool>(columns, false));

        for (int x = 0; x < columns; ++x) {
            dfs(heights, pacific_access, x, 0);
            dfs(heights, atlantic_access, x, rows - 1);
        }

        for (int y = 0; y < rows; ++y) {
            dfs(heights, pacific_access, 0, y);
            dfs(heights, atlantic_access, columns - 1, y);
        }

        vector<vector<int>> results;
        for (int y = 0; y < rows; ++y) {
            for (int x = 0; x < columns; ++x) {
                if (atlantic_access[y][x] && pacific_access[y][x]) {
                    results.push_back({y, x});
                }
            }
        }
        return results;
    }

    void dfs(const vector<vector<int>>& heights, vector<vector<bool>>& ocean_visits, int x, int y) {
        int rows = heights.size();
        int columns = heights[0].size();

        int current_height = heights[y][x];
        ocean_visits[y][x] = true;
        // go left
        int left_x = x - 1;
        if (left_x >= 0 && !ocean_visits[y][left_x] && heights[y][left_x] >= current_height) {
            dfs(heights, ocean_visits, left_x, y);
        }
        // go right
        int right_x = x + 1;
        if (right_x < columns && !ocean_visits[y][right_x] && heights[y][right_x] >= current_height) {
            dfs(heights, ocean_visits, right_x, y);
        }
        // go up
        int up_y = y - 1;
        if (up_y >= 0 && !ocean_visits[up_y][x] && heights[up_y][x] >= current_height) {
            dfs(heights, ocean_visits, x, up_y);
        }
        // go down
        int down_y = y + 1;
        if (down_y < rows && !ocean_visits[down_y][x] && heights[down_y][x] >= current_height) {
            dfs(heights, ocean_visits, x, down_y);
        }
    }
};
