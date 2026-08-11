class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<pair<int, int>> dp(nums.size());
        dp[0]={nums[0], nums[0]};
        int minProduct = nums[0], maxProduct = nums[0];
        for(int i=1; i<nums.size();i++){
            int oldMax = dp[i-1].first;
            int oldMin = dp[i-1].second;
            int newMax = max(nums[i], max(oldMax*nums[i], oldMin*nums[i]));
            int newMin = min(nums[i], min(oldMax*nums[i], oldMin*nums[i]));
            dp[i] = {newMax, newMin};
            maxProduct = max(maxProduct, max(newMax, newMin));
        }
        return maxProduct;
    }
};
