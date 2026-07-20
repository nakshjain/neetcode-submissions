class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> pad = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans;
        if(!digits.size()) return ans;
        dfs(ans, digits, pad, 0, "");
        return ans;
    }

    void dfs(vector<string>& ans, string digits, vector<string>& pad,  int index, string tmp){
        if(tmp.size()==digits.size()){
            ans.push_back(tmp);
            return;
        }
        char digitChar=digits[index];
        int digit=digitChar-'0';
        for(int i=0;i<pad[digit].size();i++){
            tmp.push_back(pad[digit][i]);
            dfs(ans, digits, pad, index+1, tmp);
            tmp.pop_back();
        }
    }
};
