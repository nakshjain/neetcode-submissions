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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        string s;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int count = q.size();
            while(count--){
                TreeNode* root = q.front();
                q.pop();
                if(!root) s+="N-";
                else{
                    s+=to_string(root->val)+"-";
                    q.push(root->left);
                    q.push(root->right);
                }
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0 || data=="N-") return nullptr;
        int i=0, l=0;
        while(data[i+l]!='-'){
            l++;
        }
        TreeNode* root=new TreeNode(stoi(data.substr(i, l)));
        i=i+l+1;
        l=0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(!node) continue;
            while(data[i+l]!='-'){
                l++;
            }
            node->left = data.substr(i, l) != "N" ? new TreeNode(stoi(data.substr(i, l))) : nullptr;
            i=i+l+1;
            l=0;
            q.push(node->left);
            while(data[i+l]!='-'){
                l++;
            }
            node->right = data.substr(i, l) != "N" ? new TreeNode(stoi(data.substr(i, l))) : nullptr;
            i=i+l+1;
            l=0;
            q.push(node->right);
        }
        return root;
    }
};
