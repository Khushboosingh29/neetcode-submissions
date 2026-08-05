class Solution {
public:
 vector<vector<int>>res;
 int n;
 void solve(int idx,vector<int>& nums,vector<int> &temp){
    res.push_back(temp);
    for(int i=idx;i<n;i++){
        if(i>idx && nums[i]==nums[i-1])
            continue;
        temp.push_back(nums[i]);
        solve(i+1,nums,temp);
        temp.pop_back();
        }
 }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        vector<int>temp;
        n=nums.size();
        sort(nums.begin(),nums.end());
        solve(0,nums,temp);
        return res;
    }
};