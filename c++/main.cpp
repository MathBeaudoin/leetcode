#include "./152-maximum-product-subarray/Solution.cpp"
#include <iostream>
#include "./utils/ListNode.h"
#include "./utils/PrettyPrint.h"

using namespace std;

int main() {
    vector<int> values = {2, -3, 2, -4, -2, 5};
    vector<vector<int>> vals = {{1, 2}, {3, 4}};
    auto s = Solution().maxProduct(values);
    cout << s << endl;

    return 0;
}