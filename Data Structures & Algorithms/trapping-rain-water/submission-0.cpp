class Solution {
public:
    int trap(vector<int>& height) {
        int ans=0, n=height.size(), currMax=height[0];
        vector<int> prefix(n, 0), suffix(n, 0);
        for(int i=1;i<n;i++){
            prefix[i]=currMax;
            currMax=max(currMax, height[i]);
        }
        currMax=height[n-1];
        for(int i=n-2;i>=0;i--){
            suffix[i]=currMax;
            currMax=max(currMax, height[i]);
        }
        for(int i=1;i<n;i++){
            if(height[i]<min(prefix[i], suffix[i])) ans+=min(prefix[i], suffix[i])-height[i];
        }
        return ans;
    }
};
