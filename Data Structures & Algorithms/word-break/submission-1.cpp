class Solution {
public:
unordered_set<string>st;
int n;

bool solve(int i,string &s, vector<int>&dp){
    if(i==n)
        return true;
    if(st.find(s)!=st.end())
        return true;
        if(dp[i]!=-1)
            return dp[i];
    for(int l=1;l<n;l++){
        string temp=s.substr(i,l);
        if(st.find(temp)!=st.end() && solve(i+l,s,dp))
            return dp[i]= true; 
    }
    return dp[i]= false;
}
    bool wordBreak(string s, vector<string>& wordDict) {
        n=s.size();
        vector<int>dp(n+1,-1);
        for(string word:wordDict){
            st.insert(word);
        }
        return solve(0,s,dp);
        
    }
};
