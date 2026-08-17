class Solution {
public:
int solve(int i, int amount,vector<int>& coins,vector<vector<int>> &dp){
    if(i==0){
        if(amount%coins[i]==0)
            return amount/coins[i];
        else 
            return 1e9;
    }
    if(dp[i][amount]!=-1)
        return dp[i][amount];
    int t=INT_MAX;
    if(amount>=coins[i])
         t=1+solve(i,amount-coins[i],coins,dp);
    int nt=solve(i-1,amount,coins,dp);
    return dp[i][amount]=min(t,nt);

}
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
       int ans=  solve(n-1,amount,coins,dp);
       return (ans >= 1e9) ? -1 : ans;
    }
};
