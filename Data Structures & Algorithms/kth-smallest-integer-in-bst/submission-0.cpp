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
    int ans = -1;
    int kthSmallest(TreeNode* root, int k) {
        int tmp = helper(root, k, 0);
        return ans;
    }

    int helper(TreeNode* root, int k, int index){
        if(!root) return index;
        int leftIndex = helper(root->left, k, index);
        int curIndex = leftIndex + 1;
        if(curIndex==k){
            ans=root->val;
        }
        int rightIndex = helper(root->right, k, curIndex);
        return rightIndex;
    }
};
