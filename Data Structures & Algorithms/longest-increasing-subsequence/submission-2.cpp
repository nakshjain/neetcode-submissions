class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(), ans=0;
        vector<int> dp(n, 0);
        for(int i=0;i<n;i++){
            int count=1;
            for(int j=i-1;j>=0;j--){
                if(nums[i]>nums[j]){
                    count=max(count, dp[j]+1);
                }
            }
            dp[i]=count;
            ans=max(ans, count);
        }
        return ans;
    }
};
