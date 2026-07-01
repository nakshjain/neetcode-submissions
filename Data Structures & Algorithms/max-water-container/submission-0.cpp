class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxWater=0, l=0, r=heights.size()-1;
        while(l<r){
            int water=(r-l)*min(heights[l], heights[r]);
            maxWater=max(water, maxWater);
            if(heights[l]>heights[r]){
                r--;
            } else l++;
        }
        return maxWater;
    }
};
