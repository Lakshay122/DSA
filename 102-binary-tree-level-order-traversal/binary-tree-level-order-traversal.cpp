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
    vector<vector<int>> levelOrder(TreeNode* root) {
        // code here
        queue<pair<TreeNode*, int>> q;
        vector<vector<int>> ans;

        if(root)q.push({root, 0});

        while (!q.empty()) {
            pair<TreeNode*, int> temp = q.front();
            q.pop();
            if (temp.second >= ans.size()) {
                ans.push_back({});
            }
           

            ans[temp.second].push_back(temp.first->val);
            if (temp.first->left!=nullptr)
                q.push({temp.first->left, temp.second + 1});
            if (temp.first->right!=nullptr)
                q.push({temp.first->right, temp.second + 1});
        }
        return ans;
    }
};