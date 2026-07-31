class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>mx;
        for(int num:stones){
            mx.push(num);
        }
        while(mx.size()>1){
            int first=mx.top();
            mx.pop();
            int second=mx.top();
            mx.pop();
            if(first>second){
            int res=first-second;
            mx.push(res);
            }
           
        }
         mx.push(0);
        return mx.top();
    }
};
