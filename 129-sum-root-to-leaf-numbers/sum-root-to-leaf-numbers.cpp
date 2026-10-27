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
    int ans = 0;

public:
    void sum(TreeNode* root, int prevNumber) {

        if (!root)
            return ;
        if (!root->left && !root->right) {
            // this is the soltion
            int calculatedNumber = prevNumber * 10 + root->val;
            ans += calculatedNumber;
        }
        int currNumber = prevNumber * 10 + root->val;
        if (root->left)
            sum(root->left, currNumber);
        if (root->right)
            sum(root->right, currNumber);
    }
    int sumNumbers(TreeNode* root) {
        sum(root, 0);
        return ans;
    }
};