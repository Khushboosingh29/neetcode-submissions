class MedianFinder {
public:
    priority_queue<int>lmh;
    priority_queue<int,vector<int>,greater<int>>rmh;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
         if(lmh.empty() || lmh.top()>=num)
            lmh.push(num);
        else
            rmh.push(num);
        if(lmh.size()>rmh.size()+1)
        {
            int el=lmh.top();
            lmh.pop();
            rmh.push(el);
        } 
        else if(lmh.size()<rmh.size())
        {
            int el=rmh.top();
            rmh.pop();
            lmh.push(el);
        }        
    }
    
    double findMedian() {
        if(lmh.size()==rmh.size()){
            double avg=(lmh.top()+rmh.top())/2.0;
            return avg;
        }
        else
        return lmh.top();
        
    }
};
