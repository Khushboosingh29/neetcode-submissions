class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>mpp;
        if(s.size()!=t.size())
            return false;
        for(char num1:s){
            mpp[num1]++;
        }
        for(char num2:t){
            mpp[num2]--;
        }
        for(auto [ch,cnt]:mpp){
            if(cnt!=0)
                return false;
        }
        return true;
    }
};
