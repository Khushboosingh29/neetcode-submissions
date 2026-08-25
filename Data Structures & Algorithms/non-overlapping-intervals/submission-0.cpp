class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int cnt=0;
        vector<int>pair=intervals[0];
        for(int j=1;j<intervals.size();j++){
            if(pair[1]<=intervals[j][0])
                {
                    pair=intervals[j];
                }
            else if(pair[1]>intervals[j][0]){
                if(pair[1]>intervals[j][1])
                {
                        pair=intervals[j];
                        cnt++;
                }
                else{
                        cnt++;
                }
            }

        }
        return cnt;
        
    }
};
