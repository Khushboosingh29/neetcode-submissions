class Solution {
public:
 unordered_map<int,bool>mpp;
    bool isHappy(int n) {
       
    
        if(mpp.find(n)!=mpp.end())
            return false;
        mpp[n]=true;
        int sum=0;
        while(n!=0){
            int dig=n%10;
            sum+=dig*dig;
            n=n/10;

        }
        if(sum==1)
            return true;
       return  isHappy(sum);


        
    }
};
