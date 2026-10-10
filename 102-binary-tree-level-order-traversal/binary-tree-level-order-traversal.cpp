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
// class Solution {
// public:
//     vector<vector<int>> levelOrder(TreeNode* root) {
//         // code here
//         queue<pair<TreeNode*, int>> q;
//         vector<vector<int>> ans;

//         if(root)q.push({root, 0});

//         while (!q.empty()) {
//             pair<TreeNode*, int> temp = q.front();
//             q.pop();
//             if (temp.second >= ans.size()) {
//                 ans.push_back({});
//             }

//             ans[temp.second].push_back(temp.first->val);
//             if (temp.first->left!=nullptr)
//                 q.push({temp.first->left, temp.second + 1});
//             if (temp.first->right!=nullptr)
//                 q.push({temp.first->right, temp.second + 1});
//         }
//         return ans;
//     }
// };

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        // code here
        queue<TreeNode*> q;
        vector<vector<int>> ans;

        if (root)
            q.push(root);

        while (!q.empty()) {
            vector<int> level;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* temp = q.front();
                q.pop();
                
                level.push_back(temp->val);
                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
            }
            ans.push_back(level);
           
        }
        return ans;
    }
};