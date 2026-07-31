class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>mpp(nums.begin(),nums.end());
        int maxi=0;
        for(int num:nums)
        {
         if(mpp.find(num-1)==mpp.end())
         {
            int lenght=1;
        while(mpp.find(num+lenght)!=mpp.end()){
            lenght++;
        }
           maxi= max(lenght,maxi);

        }
        }
        return maxi;
        
    }
};
