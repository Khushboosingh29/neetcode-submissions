class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>minq;
        for(int num:nums){
            minq.push(num);
    
        }
        while(minq.size()>k){
            minq.pop();
        }
        return minq.top();
    }
};
