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
    int maxSum=-1001;
    int maxPathSum(TreeNode* root) {
        maxSum = root->val;
        int tmp = helper(root);
        return maxSum;
    }

    int helper(TreeNode* root){
        if(!root) return -1001;
        int leftMaxSum = helper(root->left);
        int rightMaxSum =helper(root->right);
        int childMax = max(leftMaxSum, rightMaxSum);
        int currMax = childMax > 0 ? root->val + childMax : root->val;
        maxSum = max(maxSum, max(childMax, max(currMax, root->val + leftMaxSum + rightMaxSum)));
        return currMax;
    }
};
