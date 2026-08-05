class Solution {
public:
vector<string>res;
void solve(string temp,int n,int open,int close){
    if(temp.size()==2*n){
        res.push_back(temp);
        return;
    }

        if(open<n){
        temp.push_back('(');
        solve(temp,n,open+1,close);
        temp.pop_back();
        }
        if(close<open){    
        temp.push_back(')');
        solve(temp,n,open,close+1);
        temp.pop_back();
         }
}
    vector<string> generateParenthesis(int n) {
        int open =0;
        int close=0;
        string temp="";
        solve(temp,n,open,close);
        return res;
    }
};
