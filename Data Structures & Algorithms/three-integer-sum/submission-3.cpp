class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size();i++){
            if(i!=0 && nums[i]==nums[i-1]) continue;
            int l=i+1, r=nums.size()-1;
            while(l<r){
                if(i+1!=l && nums[l]==nums[l-1]) l++;
                else if (r!=nums.size()-1 && nums[r]==nums[r+1]) r--;
                else{
                    
                int sum=nums[i]+nums[l]+nums[r];
                if(sum==0){
                    ans.push_back({nums[i],nums[l],nums[r]});
                    r--;
                    l++;
                } else if(sum>0) r--;
                else l++;
                }
            }
        }
        return ans;
    }
};
