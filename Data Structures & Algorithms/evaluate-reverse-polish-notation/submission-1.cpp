class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(string s:tokens)
        {
            if(s=="+")
            {

                int num1=st.top();
                st.pop();
                int num2=st.top();
                st.pop();
                int res=num1+num2;
                 st.push(res);
            }
            else if(s=="-" )
            {

                int num1=st.top();
                st.pop();
                int num2=st.top();
                st.pop();
                int res=num2-num1;
                 st.push(res);
            }
            else if(s=="*" )
            {

                int num1=st.top();
                st.pop();
                int num2=st.top();
                st.pop();
                int res=num1*num2;
                 st.push(res);
            }
            else if(s=="/" )
            {

                int num1=st.top();
                st.pop();
                int num2=st.top();
                st.pop();
                int res=num2/num1;
                 st.push(res);
            }else {
                st.push(stoi(s));
            }
            
        }
        return st.top();
    }
};
