class Solution {
public:
 vector<vector<string>>res;
 int n;
 bool ispalindrome(string s,int l,int r){
    while(l<r){
        if(s[l]!=s[r])
            return false;
        l++;
        r--;
    }
    return true;
 }
 void solve(int idx,vector<string>curr,string s){
    if(idx==n){
        res.push_back(curr);
        return;
    }

    for(int i=idx;i<n;i++){
        if(ispalindrome(s,idx,i))
        {
            curr.push_back(s.substr(idx,i-idx+1));
            solve(i+1,curr,s);
            curr.pop_back();
        }
    }
 }
    vector<vector<string>> partition(string s) {
        vector<string>curr;
      
        n=s.size();
        solve(0,curr,s);
        return res;
        
    }
};
