/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        // we are trying to solve this question using dfs and bfs
        // for bfs we are going to use the queue
        queue<TreeNode*> q;
        if(root) q.push(root);
        int ans = 0;
        while (!q.empty()) {
            int n = q.size();
            ans++;
            while (n--) {
                TreeNode* top = q.front();
                q.pop();
                if (top->left)
                    q.push(top->left);
                if (top->right)
                    q.push(top->right);
            }
        }
        return ans;
    }
};