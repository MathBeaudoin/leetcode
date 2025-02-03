#include "./23-merge-k-sorted-lists/Solution.cpp"
#include <iostream>
#include "./utils/ListNode.h"

using namespace std;

int main() {
    vector<ListNode*> lists = {
        make_list_node_from_values({1, 4, 5}),
        make_list_node_from_values({1, 3, 4}),
        make_list_node_from_values({2, 6})};

    auto s = Solution().mergeKLists(lists);
    cout << s << endl;

    return 0;
}