#include <iostream>
#include <vector>

using namespace std;

/**
* Definition for singly-linked list.
*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* pointer = head;
        int num_of_nodes = 0;
        while (pointer != nullptr) {
            ++num_of_nodes;
            pointer = pointer->next;
        }

        if (n == num_of_nodes) {
            return head->next;
        }

        pointer = head;
        if (num_of_nodes != 1) {
            int current_index = 0;
            while (current_index != num_of_nodes - n - 1) {
                ++current_index;
                pointer = pointer->next;
            }
        }

        if (pointer == nullptr) {
            return nullptr;
        }

        if (pointer->next == nullptr) {
            return pointer;
        }

        pointer->next = pointer->next->next;

        return head;
    }
};