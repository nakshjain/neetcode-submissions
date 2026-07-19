class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> tmp;
        dfs(ans, nums, target, tmp, 0, 0);
        return ans;
    }

    void dfs(vector<vector<int>>& ans, const vector<int>& nums, const int target, vector<int>& tmp, int curSum, int index){
        if(curSum>target) return;
        if(curSum==target){
            ans.push_back(tmp);
            return;
        }
        for(int i=index;i<nums.size();i++){
            tmp.push_back(nums[i]);
            dfs(ans, nums, target, tmp, curSum+nums[i], i);
            tmp.pop_back();
        }
    }
};
