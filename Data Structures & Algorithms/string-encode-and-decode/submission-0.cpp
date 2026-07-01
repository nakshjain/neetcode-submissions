class Solution {
public:

    string encode(vector<string>& strs) {
        int n=strs.size();
        string encoded=to_string(n)+"_";
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
        s=s.substr(index+n+1, s.size()-1);
        return newS;
    }

    vector<string> decode(string s) {
        vector<string> decoded;
        int index = s.find("_");
        string length = s.substr(0, index);
        int n = stoi(length);
        s = s.substr(index+1, s.size());
        while(n--){
            decoded.push_back(helper(s));
        }
        return decoded;
    }
};
