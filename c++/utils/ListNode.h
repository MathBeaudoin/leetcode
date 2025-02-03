//
// Created by mathi on 2025-01-31.
//

#ifndef LISTNODE_H
#define LISTNODE_H

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

inline void print_list_node(ListNode* node) {
    ListNode* traversal = node;
    std::cout << "{ ";
    while (traversal != nullptr) {
        std::cout << traversal->val << " ";
        traversal = traversal->next;
    }
    std::cout << "}" << std::endl;
}

inline ListNode* make_list_node_from_values(const std::vector<int>& values) {
    if (values.empty()) {
        return nullptr;
    }

    ListNode* node = new ListNode(values[0]);
    ListNode* traversal = node;
    for (int i = 1; i < values.size(); ++i) {
        traversal->next = new ListNode(values[i]);
        traversal = traversal->next;
    }

    std::cout << "- Creating list node: ";
    print_list_node(node);

    return node;
}

#endif //LISTNODE_H
