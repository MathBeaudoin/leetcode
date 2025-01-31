#include <iostream>
#include <vector>
#include "../utils/ListNode.h"

using namespace std;

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr && list2 == nullptr) {
            return nullptr;
        }

        if (list1 == nullptr) {
            return list2;
        }

        if (list2 == nullptr) {
            return list1;
        }

        ListNode* node = new ListNode();
        ListNode* traversal = node;
        while (true) {
            if (list1 == nullptr && list2 == nullptr) {
                break;
            }

            if (list1 == nullptr) {
                traversal->val = list2->val;
                traversal->next = list2->next;
                break;
            }

            if (list2 == nullptr) {
                traversal->val = list1->val;
                traversal->next = list1->next;
                break;
            }

            if (list1->val <= list2->val) {
                traversal->val = list1->val;
                list1 = list1->next;
            } else {
                traversal->val = list2->val;
                list2 = list2->next;
            }

            traversal->next = new ListNode();
            traversal = traversal->next;
        }

        return node;
    }
};