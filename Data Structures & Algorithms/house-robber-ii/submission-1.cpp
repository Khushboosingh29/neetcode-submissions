class Solution {
public:
int solve(vector<int>& nums,int i, vector<int> &dp,int l){
    if(i>=l)
        return 0;
    if(dp[i]!=-1)
        return dp[i];
    int t=nums[i]+solve(nums,i+2,dp,l);
    int nt=solve(nums,i+1,dp,l);
    return dp[i]=max(t,nt);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
        
        vector<int>dp1(n+1,-1);
        vector<int>dp2(n+1,-1);
        return max(solve(nums,0,dp1,n-1),solve(nums,1,dp2,n));
    }
};
