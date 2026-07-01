class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded;
        for(string s: strs){
            int m=s.size();
            encoded+=to_string(m)+"_"+s;
        }
        return encoded;
    }

    string helper(string& s){
        int index = s.find("_");
        string length = s.substr(0, index);
        int n=stoi(length);

        string newS = s.substr(index+1, n);
        s=s.substr(index+n+1);
        return newS;
    }

    vector<string> decode(string s) {
        vector<string> decoded;
        while(s.size()!=0){
            decoded.push_back(helper(s));
        }
        return decoded;
    }
};
