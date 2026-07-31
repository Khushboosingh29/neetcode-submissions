class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
      
        set<vector<int>>st;
        int n=nums.size();
        for(int i=0;i<n;i++ ){
            unordered_set<int>mpp;
            for(int j=i+1;j<n;j++)
            {
                int target=-(nums[i]+nums[j]);
                if(mpp.find(target)!=mpp.end()){
                    vector<int>temp={nums[i],nums[j],target};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }
                mpp.insert(nums[j]);
            }
        }
        vector<vector<int>>ans(st.begin(),st.end());
        return ans;
    }
};
