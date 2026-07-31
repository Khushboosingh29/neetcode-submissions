class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int,greater<int>>mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        priority_queue<pair<int,int>>pq;
        
        vector<int>res;
        for(auto it:mpp){
            pq.push({it.second,it.first});
        }
        while(k>0 && !pq.empty())
        {
         res.push_back(pq.top().second);
         pq.pop();
         k--;
        }
      return res;  
    }
};
