class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        vector<int>ans;
        unsigned long long res=0;
        for(int i=0;i<n;i++){
            res=res*10+digits[i];
        }
        res=res+1;
        while(res!=0){
            int num=res%10;
            ans.push_back(num);
            res=res/10;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
