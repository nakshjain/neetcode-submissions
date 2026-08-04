class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int ans=0;
        for(const int i:nums){
            if(st.find(i-1)!=st.end()) continue;
            int length=1;
            int curNum=i;
            while(st.find(curNum+1)!=st.end()){
                length++;
                curNum++;
            }
            ans = max(ans, length);
        }
        return ans;
    }
};
