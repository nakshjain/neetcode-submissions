class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<int> dp(n+1, 0);
        dp[0]=1;
        for(int i=1;i<=n;i++){
            for(string word: wordDict){
                int len = word.length();
                if(i>=len && dp[i-len] && word==s.substr(i-len, len)) dp[i]=1;
            }
        }
        return dp[n]==1;
    }
};
