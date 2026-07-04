class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char c: s){
            if((c=='(') || c == '{' || c=='[') st.push(c);
            else{
                if(st.size()==0) return false;
                char top = st.top();
                if(top=='(' && c==')') st.pop();
                else if(top=='{' && c=='}') st.pop();
                else if(top=='[' && c==']') st.pop();
                else return false;
            }
        }
        return st.size()==0;
    }
};
