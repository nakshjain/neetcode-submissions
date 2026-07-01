class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        int arr[26]={0};
        for(char c:s){
            arr[c-'a']++;
        }
        for(char c:t){
            arr[c-'a']--;
            if(arr[c-'a']<0) return false;
        }
        return true;
    }
};
