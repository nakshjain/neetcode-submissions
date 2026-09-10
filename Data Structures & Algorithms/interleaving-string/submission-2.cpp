class Solution {
private:
    bool dfs(string& s1, string& s2, string& s3, int i, int j, vector<vector<int>>& dp){
        int k=i+j;
        if(k==s3.size()) return true;
        if(i==s1.size() && j==s2.size()) return false;
        if(dp[i][j]!=-1) return dp[i][j];
        bool ans = false;
        if(i<s1.size() && s1[i]==s3[k]){
            ans = ans || dfs(s1, s2, s3, i+1, j, dp);
        }
        if(j<s2.size() && s2[j]==s3[k]){
            ans = ans || dfs(s1, s2, s3, i, j+1, dp);
        }
        return dp[i][j]=ans;
    }

public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s3.size()!=s1.size()+s2.size()) return false;
        vector<vector<int>> dp(s1.size()+1, vector<int>(s2.size()+1, -1));
        return dfs(s1, s2, s3, 0, 0, dp);
    }
};
