class Solution {
public:
int n;
int solve(int i,int amount, vector<int>& coins,vector<vector<int>>
&dp){
    if(i==n)
        return 0;
    if(amount==0)
        return 1;
    if(dp[i][amount]!=-1)
        return dp[i][amount];
    int take=0;
    if(coins[i]<=amount)
        take=solve(i,amount-coins[i],coins,dp);
    int ntake=solve(i+1,amount,coins,dp);
    return dp[i][amount]=take+ntake;
        
}
    int change(int amount, vector<int>& coins) {

        n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
       
        return solve(0,amount,coins,dp);
    }
};
