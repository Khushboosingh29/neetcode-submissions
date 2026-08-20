class Solution {
public:
int n;
int solve(vector<int>& prices,int day,int n,int buy,vector<vector<int>> &dp){
    if(day>=n)
        return 0;
    int profit=0;
    if(dp[day][buy]!=-1)
        return dp[day][buy];
    if(buy){
        int b=solve(prices,day+1,n,false,dp)-prices[day];
        int nb=solve(prices,day+1,n,true,dp);
        profit=max({profit,b,nb});

    }
    else{
        int s=prices[day]+solve(prices,day+2,n,true,dp);
        int ns=solve(prices,day+1,n,false,dp);
        profit=max({profit,s,ns});

    }
    return dp[day][buy]= profit;
}
    int maxProfit(vector<int>& prices) {
        n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        bool buy=true;
        return solve(prices,0,n,buy,dp);
        
    }
};
