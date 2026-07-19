class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> tmp;
        dfs(ans, candidates, target, tmp, 0, 0);
        return ans;
    }

    void dfs(vector<vector<int>>& ans, const vector<int>& candidates, const int target, vector<int>& tmp, int index, int currSum){
        if(currSum>target) return;
        if(currSum==target){
            ans.push_back(tmp);
            return;
        }
        for(int i=index;i<candidates.size();i++){
            if(i>index && candidates[i]==candidates[i-1]) continue;
            tmp.push_back(candidates[i]);
            dfs(ans, candidates, target, tmp, i+1, currSum+candidates[i]);
            tmp.pop_back();
        }
    }
};
