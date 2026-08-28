#include <cstring>
class Solution {
public:
int n,m;
int t[21][21];
bool solve(int i,int j,string s, string p){
    if(j==m){
        if(i==n)
            return true;
        return false;
    }
    if(t[i][j]!=-1)
        return t[i][j];
    bool match=false;
    if(i<n && ((s[i]==p[j]) || p[j]=='.')){
        match=true;
    }

    if(j + 1 < m && p[j+1]=='*'){
        bool ntake=solve(i,j+2,s,p);
        bool take=match &&  solve(i+1,j,s,p);

        return t[i][j]= take || ntake;
    }
    return t[i][j]=match && solve(i+1,j+1,s,p);
}
    bool isMatch(string s, string p) {
        n=s.size();
        m=p.size();
        memset(t,-1,sizeof(t));
       return  solve(0,0,s,p);
        
    }
};