/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int ans=-2000;
public: 
    int maxPathSum2(TreeNode* root){
       if (!root) return 0;

        int left = max(0, maxPathSum2(root->left));
        int right = max(0, maxPathSum2(root->right));

        int onePath = root->val + max(left, right);

        ans = max(ans, root->val + left + right);

        return onePath;

    }
    int maxPathSum(TreeNode* root) {
    maxPathSum2(root);
    return ans;
    }
};