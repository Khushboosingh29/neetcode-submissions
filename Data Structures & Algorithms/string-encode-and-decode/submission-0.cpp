class Solution {
public:

    string encode(vector<string>& strs) {
        string s="";
        for(string st:strs){
            int n=st.size();
            s+=(to_string(n)+'#'+st);
        }
    return s;
    }

    vector<string> decode(string s) {
        vector<string>res;
        int i=0;
        while(i<s.size()){
            int j=i;
            while(s[j]!='#'){
                j++;
            }
            int len=stoi(s.substr(i,j-i));
            i=j+1;
            res.push_back(s.substr(i,len));
            i+=len;
            }
    return res;
        }

    
};
