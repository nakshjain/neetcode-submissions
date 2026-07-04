class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(string s : tokens){
            if(s=="+" || s=="-" || s=="*" || s=="/"){
                int num2 = st.top();
                st.pop();
                int num1 = st.top();
                st.pop();
                int num3=0;
                if(s=="+") num3=num1+num2;
                else if(s=="-") num3=num1-num2;
                else if(s=="*") num3=num1*num2;
                else if(s=="/") num3=num1/num2;
                st.push(num3);
            } else {
                int num = stoi(s);
                st.push(num);
            }
        }
        return st.top();
    };
};
