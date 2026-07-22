class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> map;
        for(const char c: s1) map[c]++;
        int i=0, j=0;
        unordered_map<char, int> tmp=map;
        while(j<s2.size()){
            if(!tmp[s2[j]]){
                tmp=map;
                i++;
                j=i;
            } else{
                tmp[s2[j]]--;
                if(j-i+1==s1.size()) return true;
                j++;
            }
        }
        return false;
    }
};
