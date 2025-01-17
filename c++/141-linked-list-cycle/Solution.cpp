#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr) {
            return false;
        }

        ListNode* fast = head->next;
        ListNode* slow = head;

        while (fast != nullptr && fast != slow) {
            slow = slow->next;
            fast = fast->next;

            if (fast != nullptr && fast != slow) {
                fast = fast->next;
            }
        }

        if (fast == nullptr) {
            return false;
        }

        return true;
    }
};