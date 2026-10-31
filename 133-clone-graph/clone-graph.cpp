/*
// Definition for a Node.
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
*/

class Solution {
public:
    Node* solve(Node* root, unordered_map<int, Node*>& vis) {
        // create node for this
       
        Node* clonedRoot = new Node(root->val);
        vis[root->val] = clonedRoot;
        vector<Node*> neighbors;
        for (int i = 0; i < root->neighbors.size(); i++) {
            if (!vis[root->neighbors[i]->val]) {
                Node* temp = solve(root->neighbors[i], vis);
                neighbors.push_back(temp);
            } else {
                neighbors.push_back(vis[root->neighbors[i]->val]);
            }
        }
        clonedRoot->neighbors = neighbors;
       
        return clonedRoot;
    }
    Node* cloneGraph(Node* node) {

        // need to create a kind of map
        // <int, Node*>// to check is it visited
        if (!node)
            return node;
        unordered_map<int, Node*> vis;
        return solve(node, vis);
    }
};