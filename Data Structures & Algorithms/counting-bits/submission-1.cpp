class Solution {
public:
int count(int num){
    int cnt=0;
    while(num!=0){
        num=num&(num-1);
        cnt++;
    }
    return cnt;

}
    vector<int> countBits(int n) {
        vector<int>ans;
        for(int i=0;i<=n;i++){
            ans.push_back(count(i));
        }
        return ans;
    }
};
