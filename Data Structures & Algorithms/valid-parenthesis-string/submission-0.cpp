#include <cstring>
class Solution {
public:
int n;
int t[101][101];
bool solve(int i,int o,string &s){
    if(i==n)
        return (o==0);
        bool valid=false;
    if(t[i][o]!=-1)
        return t[i][o];
    if(s[i]=='(')
       valid=valid || solve(i+1,o+1,s);
    else if(s[i]==')')
    {   if(o>=1)
           valid=valid || solve(i+1,o-1,s);
    }
    else
    {
        valid= valid ||solve(i+1,o+1,s);
        if(o>=1)
           valid=valid || solve(i+1,o-1,s);
        valid= valid ||solve(i+1,o,s);
    }
    return t[i][o]=valid;
}
    bool checkValidString(string s) {
        n=s.size();
        memset(t,-1,sizeof(t));
       return solve(0,0,s);
        
    }
};
