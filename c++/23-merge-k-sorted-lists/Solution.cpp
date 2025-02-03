#include <iostream>
#include <vector>
#include "../utils/ListNode.h"

using namespace std;

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return nullptr;
        }

        ListNode* merged_lists = new ListNode();
        ListNode* traversal = merged_lists;
        while (!lists.empty()) {
            int min_val = INT32_MAX;
            for (ListNode* node : lists) {
                if (node != nullptr && node->val < min_val) {
                    min_val = node->val;
                }
            }

            for(auto node_it = lists.begin(); node_it != lists.end(); ++node_it) {
                while (*node_it != nullptr && (*node_it)->val <= min_val) {
                    traversal->next = new ListNode();
                    traversal = traversal->next;
                    traversal->val = (*node_it)->val;
                    *node_it = (*node_it)->next;
                }

                if (*node_it == nullptr) {
                    node_it = lists.erase(node_it);
                    --node_it;
                    cout << "deleted vector" << endl;
                }
            }
        }

        return merged_lists->next;
    }
};