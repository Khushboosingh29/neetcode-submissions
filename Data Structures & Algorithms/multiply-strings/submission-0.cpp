class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0" || num2=="0")
            return "0";
        int n=num1.size();
        int m=num2.size();
        vector<int>res(n+m,0);
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--)
            {
                int dig1=num1[i]-'0';
                int dig2=num2[j]-'0';
                int sum=dig1*dig2+res[i+j+1];
                res[i+j+1]=sum%10;
                res[i+j]+=sum/10;
            }
        }
        int st=0;
        while(st<res.size() && res[st]==0){
            st++;
        }
        string ans="";
        for(int k=st;k<res.size();k++){
            ans+=to_string(res[k]);
        }
        return ans;
    }
};
