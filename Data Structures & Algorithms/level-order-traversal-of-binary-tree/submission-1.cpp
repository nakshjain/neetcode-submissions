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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        vector<int> tmp;
        queue<TreeNode*> nodes;
        nodes.push(root);
        nodes.push(nullptr);
        while(!nodes.empty()){
            TreeNode* topNode = nodes.front();
            nodes.pop();
            if(!topNode){
                ans.push_back(tmp);
                tmp.clear();
                if(!nodes.empty()) nodes.push(nullptr);
            } else {
                tmp.push_back(topNode->val);
                if(topNode->left) nodes.push(topNode->left);
                if(topNode->right) nodes.push(topNode->right);
            }
        }
        return ans;
    }
};
