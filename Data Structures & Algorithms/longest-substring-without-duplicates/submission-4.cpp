class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> map;
        int l=0, r=0, maxLength=0;
        while(r<s.length()){
            if(map.find(s[r])!=map.end() && map[s[r]]>=l){
                l=map[s[r]]+1;
            }
            map[s[r]]=r;
            r++;
            maxLength=max(maxLength, (r-l));
        }
        return maxLength;
    }
};
