#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*
// Definition for a Node.
*/
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }

    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) {
            return nullptr;
        }

        vector<Node*> nodes_added;

        return clone_node(node, nodes_added);
    }

private:
    Node* clone_node(Node* node, vector<Node*>& nodes_added) {
        Node* current_node = new Node(node->val);
        nodes_added.push_back(current_node);

        for (const auto& neighbour : node->neighbors) {
            auto it = find_if(nodes_added.begin(), nodes_added.end(), [neighbour] (const Node* node) {
                return node->val == neighbour->val;
            });

            if (it == nodes_added.end()) {
                Node* cloned_neighbour = clone_node(neighbour, nodes_added);
                current_node->neighbors.push_back(cloned_neighbour);
            } else {
                current_node->neighbors.push_back(*it);
            }
        }

        return current_node;
    }
};