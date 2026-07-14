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
    bool isValidBST(TreeNode* root) {
        return helper(root, INT_MIN, INT_MAX);
    }

    bool helper(TreeNode* root, int minValue, int maxValue){
        if(!root) return true;
        if(minValue < root->val && root->val < maxValue){
            return helper(root->left, minValue, root->val) && helper(root->right, root->val, maxValue);
        } else return false;
    }
};
