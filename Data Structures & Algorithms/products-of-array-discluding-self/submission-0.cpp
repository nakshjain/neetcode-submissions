class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size(), lp=1, rp=1;
        vector<int> left(n, 1), right(n,1);
        for(int i=0;i<n;i++){
            lp*=nums[i];
            left[i]=lp;
        }
        for(int i=n-1;i>=0;i--){
            rp*=nums[i];
            right[i]=rp;
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(i==0) ans.push_back(right[i+1]);
            else if(i==n-1) ans.push_back(left[i-1]);
            else ans.push_back(left[i-1]*right[i+1]);
        }
        return ans;
    }
};
