class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mpp;
        vector<int>res;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]=i;
        }
        
        for(int i=0;i<nums.size();i++){
            int k=target-nums[i];
            int j=0;
            auto it=mpp.find(k);
            if(it!=mpp.end() && it->second != i){
                 j=it->second;
                 if(i!=j)
                {res.push_back(i);
                 res.push_back(j);
                 return res;
                }
            }
        }
        
    }
};
