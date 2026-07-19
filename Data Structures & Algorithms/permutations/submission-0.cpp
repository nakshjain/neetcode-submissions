class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> tmp;
        vector<bool> used(nums.size(), false);
        dfs(ans, nums, used, tmp, 0);
        return ans;
    }

    void dfs(vector<vector<int>>& ans, const vector<int>& nums, vector<bool>& used, vector<int>& tmp, int count){
        if(count==nums.size()){
            ans.push_back(tmp);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(used[i]) continue;
            tmp.push_back(nums[i]);
            used[i]=true;
            dfs(ans, nums, used, tmp, count+1);
            tmp.pop_back();
            used[i]=false;
        }
    }
};
