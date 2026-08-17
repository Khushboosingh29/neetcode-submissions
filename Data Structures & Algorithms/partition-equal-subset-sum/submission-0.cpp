class Solution {
public:
bool solve(int i,int target,vector<int>& nums,vector<vector<int>>&dp){
    if(target==0)
        return dp[i][target]=true;
    if(i>=nums.size())
        return false;
    if(dp[i][target]!=-1)
        return dp[i][target];
    int take=false;
    if(target>=nums[i])
            take=solve(i+1,target-nums[i],nums,dp);
    int ntake=solve(i+1,target,nums,dp);
    return dp[i][target]=(take||ntake);
}
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
       
        int sum=accumulate(begin(nums),end(nums),0);
        if(sum%2!=0)
            return false;
        int target=sum/2;
         vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        return solve(0,target,nums,dp);
        
    }
};

