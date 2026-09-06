class Solution {
private:
    int dfs(int amount, vector<int>& coins, int index, vector<vector<int>>& dp){
        if(amount==0){
            return dp[amount][index]=1;
        }
        if(dp[amount][index]!=-1){
            return dp[amount][index];
        }
        int cur=0;
        for(int i=index;i<coins.size();i++){
            if(coins[i]<=amount){
                cur+=dfs(amount-coins[i], coins, i, dp);
            }
        }
        dp[amount][index]=cur;
        return cur;
    }
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(amount+1, vector<int>(coins.size(), -1));
        return dfs(amount, coins, 0, dp);
    }
};
