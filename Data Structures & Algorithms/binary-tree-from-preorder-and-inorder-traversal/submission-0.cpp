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
public:
    TreeNode* buildTree(const vector<int>& preorder, const vector<int>& inorder) {
        if (preorder.empty() || inorder.empty()) return nullptr;

        int val = preorder[0];
        TreeNode* root = new TreeNode(val);

        int i = 0;
        while (val != inorder[i]) i++;

        TreeNode* left = buildTree(
            vector<int>(preorder.begin() + 1, preorder.begin() + 1 + i),
            vector<int>(inorder.begin(), inorder.begin() + i)
        );

        TreeNode* right = buildTree(
            vector<int>(preorder.begin() + 1 + i, preorder.end()),
            vector<int>(inorder.begin() + i + 1, inorder.end())
        );

        root->left = left;
        root->right = right;

        return root;
    }
};