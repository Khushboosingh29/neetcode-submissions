class Solution {
public:
int sum;
int solve(vector<int>& nums, int target ,int i,int cs,vector<vector<int>>&dp){
    if(i==nums.size())
    {
        if(cs==target)
            return 1;
        else
            return 0;
    }
    if(dp[i][cs+sum]!=-1)
        return dp[i][cs+sum];


    int plus=solve(nums,target,i+1,cs+nums[i],dp);
    int minus=solve(nums,target,i+1,cs-nums[i],dp);
    return dp[i][cs+sum]=plus+minus;

}
    int findTargetSumWays(vector<int>& nums, int target) {
        sum=0;
        for(auto it:nums)
        {
            sum+=it;
        }
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(2*sum+1,-1));
        return solve(nums,target,0,0,dp);
        
    }
};
