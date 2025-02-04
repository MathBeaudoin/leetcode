#include "./33-search-in-rotated-sorted-array/Solution.cpp"
#include <iostream>
#include "./utils/ListNode.h"
#include "./utils/PrettyPrint.h"

using namespace std;

int main() {
    vector<int> values = {4,5,6,7,0,1,2};
    int n = 0;
    auto s = Solution().search(values, 0);
    cout << s << endl;

    return 0;
}