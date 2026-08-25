/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
         //sort(intervals.begin(),intervals.end());
            sort(intervals.begin(),intervals.end(),[](const Interval &a,const Interval &b){
            return a.start<b.start;
        });

        priority_queue<int,vector<int>,greater<int>>minheap;
        for(int j=0;j<intervals.size();j++){
            if(!minheap.empty() && minheap.top()<=intervals[j].start)
                {
                    minheap.pop();
                }
        
                minheap.push(intervals[j].end);
            
                

        }
        return minheap.size();
        
    }
};
