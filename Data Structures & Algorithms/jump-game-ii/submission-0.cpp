#include <cstring>
class Solution {
public:

int n;
int t[1005];
int solve(int i,vector<int>& nums){
    if(i>=n-1)
        return 0;
        if(t[i]!=-1)
            return t[i];
    int mini=1e9;
    for(int k=1;k<=nums[i];k++){
        mini=min(mini,1+solve(i+k,nums));
    }
    return t[i]=mini;

}
    int jump(vector<int>& nums) {
         n=nums.size();
         memset(t,-1,sizeof(t));
        return solve(0,nums);

        
    }
};

