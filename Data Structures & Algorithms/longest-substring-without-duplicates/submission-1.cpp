class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        unordered_set<char>set;
        int l=0;
        int maxi=0;
        for(int r=0;r<n;r++){
            while(set.find(s[r])!=set.end()){
                maxi=max(maxi,r-l-1);
                set.erase(s[l]);
                l++;
            }
        
                set.insert(s[r]);
                maxi=max(maxi,r-l+1);
        
        }
       return maxi; 
    }
};
