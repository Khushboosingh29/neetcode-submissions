class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ps=1;
        int ss=1;
        int maxi=INT_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(ps==0)
                ps=1;
            if(ss==0)
                ss=1;
            ps*=nums[i];
            ss*=nums[n-i-1];
            maxi=max(maxi,max(ps,ss));
        }
        return maxi;
        
    }
};
