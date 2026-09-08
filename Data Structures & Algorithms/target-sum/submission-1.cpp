class Solution {
private:
    int dfs(vector<int>&nums, int target, int i, map<pair<int, int>, int>& mp){
        if(i==nums.size()){
            return target==0;
        }
        if(mp.count({target, i})){
            return mp[{target, i}];
        }
        return mp[{target, i}]=dfs(nums, target+nums[i], i+1, mp) + dfs(nums, target-nums[i], i+1, mp);
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        map<pair<int, int>, int> mp;
        return dfs(nums, target, 0, mp);
    }
};
