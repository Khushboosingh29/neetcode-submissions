class Solution {
public:
void solve(int i,vector<int>& nums,int target,vector<int> &temp,vector<vector<int>>&ans){
    if(i==nums.size()){
        if(target==0){
            ans.push_back(temp);
        }
        return;
    }
        if(nums[i]<=target){
            temp.push_back(nums[i]);
            solve(i,nums,target-nums[i],temp,ans);
            temp.pop_back();
        }
          solve(i+1,nums,target,temp,ans);
    
}
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int>temp;
        vector<vector<int>>ans;
        solve(0,nums,target,temp,ans);
        return ans;
        
        
    }
};
