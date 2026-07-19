class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string tmp;
        dfs(ans, n, tmp, 0, 0, 0);
        return ans;
    }

    void dfs(vector<string>& ans, int n, string& tmp, int count, int open, int close){
        if(count==n*2){
            ans.push_back(tmp);
            return;
        }
        if(open<n){
            tmp.push_back('(');
            dfs(ans, n, tmp, count+1, open+1, close);
            tmp.pop_back();
        }
        if(close<open){
            tmp.push_back(')');
            dfs(ans, n, tmp, count+1, open, close+1);
            tmp.pop_back();
        }
    }
};
