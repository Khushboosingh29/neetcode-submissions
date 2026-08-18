class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int tkamai=accumulate(begin(gas),end(gas),0);
        int tkharch=accumulate(begin(cost),end(cost),0);
        if(tkamai<tkharch)
            return -1;
         int n=gas.size();
        int total=0;
        int res=0;
         for(int i=0;i<n;i++){
            total=total+gas[i]-cost[i];
            if(total<0){
                total=0;
                res=i+1;
            }
         }
         return res;
        
    }
};