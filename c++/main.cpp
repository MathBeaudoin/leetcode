#include "./153-find-minimum-in-rotated-sorted-array/Solution.cpp"
#include <iostream>
#include "./utils/ListNode.h"
#include "./utils/PrettyPrint.h"

using namespace std;

int main() {
    vector<int> values = {4,5,6,7,0,1,2};
    auto s = Solution().findMin(values);
    cout << s << endl;

    return 0;
}