class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        int n=numbers.size();
        int i=0;
        int j=n-1;
        vector<int>res;
        while(i<j)
    {
        int sum=numbers[i]+numbers[j];
        if(sum>target)
        j--;
        else if(sum<target)
        i++;
        else
           {
            res.push_back(i+1);
            res.push_back(j+1);
            break;
           }
    }
    return res;
    }
};
