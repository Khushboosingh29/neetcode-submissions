class Solution {
public:
int solve(int i,int p,vector<int> &nums, vector<vector<int>>&dp){
    if(i>=nums.size())
        return 0;
        int take=INT_MIN;
        if(dp[i][p+1]!=-1)
           return dp[i][p+1];
        if(p==-1 || nums[p]<nums[i])
            take=1+solve(i+1,i,nums,dp);
        int ntake=solve(i+1,p,nums,dp);
        return dp[i][p+1]=max(take,ntake);
            
}
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        
        return solve(0,-1,nums,dp);
    }
};
