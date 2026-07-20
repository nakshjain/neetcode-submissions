class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> tmp;
        dfs(ans, s, tmp, 0);
        return ans;
    }

    void dfs(vector<vector<string>>& ans, string s, vector<string>& tmp, int index){
        int j=1;
        while((index+j)<=s.size()){
            string subs=s.substr(index, j);
            if(isPalindrome(subs)){
                tmp.push_back(subs);
                if((index+j)==s.size()) ans.push_back(tmp);
                else dfs(ans, s, tmp, index+j);
                tmp.pop_back();
            }
            j++;
        }
    }

    bool isPalindrome(string s){
        if(s.size()<=1) return true;
        int i=0, j=s.size()-1;
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};
