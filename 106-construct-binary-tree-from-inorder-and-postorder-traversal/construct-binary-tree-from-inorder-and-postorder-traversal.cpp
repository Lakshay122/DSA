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
    int findPos(vector<int>& inorder, int target, int startIndex,
                int endIndex) {
        for (int i = startIndex; i <= endIndex; i++) {
            if (inorder[i] == target)
                return i;
        }
        return -1;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder, int index,
                        int startIndex, int endIndex) {
        if (startIndex > endIndex)
            return nullptr;

        int nodeVal = postorder[index];
        TreeNode* root = new TreeNode(nodeVal);

        // find pos of the index to create left and right
        int pos = findPos(inorder, nodeVal, startIndex, endIndex);
        if (pos == -1)
            return nullptr;

        root->right =
            buildTree(inorder, postorder, index + 1, pos + 1, endIndex);
        root->left = buildTree(inorder, postorder, index + (endIndex - pos + 1),
                               startIndex, pos - 1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        reverse(postorder.begin(), postorder.end());
        return buildTree(inorder, postorder, 0, 0, inorder.size() - 1);
    }
};