#include <cstring>
class Solution {
public:
int m,n;
int t[101][101];
int solve(int i,int j,string &word1, string &word2){
    if(i==m)
        return n-j;
    if(j==n)
        return m-i;
    if(t[i][j]!=-1)
        return t[i][j];
    if(word1[i]==word2[j])
        return t[i][j]=solve(i+1,j+1,word1,word2);
    else
    {
       int  ins=1+solve(i,j+1,word1,word2);
       int del=1+solve(i+1,j,word1,word2);
       int rep=1+solve(i+1,j+1,word1,word2);
       
       return t[i][j]=min({ins,del,rep}); 
    }
    return -1;
}
    int minDistance(string word1, string word2) {
        m=word1.size();
        n=word2.size();
        memset(t,-1,sizeof(t));

        return solve(0,0,word1,word2);
        
    }
};
