class Solution {
public:
    bool isAlphaNumeric(char c){
        if((c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9')) return true;
        return false;
    }

    bool isPalindrome(string s) {
        int l=0, r=s.size()-1;
        while(l<=r){
            if(!isAlphaNumeric(s[l])){
                l++;
                continue;
            }
            if(!isAlphaNumeric(s[r])){
                r--;
                continue;
            }
            if(tolower(s[l])!=tolower(s[r])) return false;
            l++;
            r--;
        }
        return true;
    }
};
