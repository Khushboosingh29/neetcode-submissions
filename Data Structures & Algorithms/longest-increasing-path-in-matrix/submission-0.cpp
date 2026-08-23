#include <cstring>
class Solution {
public:
int MOD=1e9+7;
vector<int>dr={0,-1,0,+1};
vector<int>dc={+1,0,-1,0};
int m,n;
int t[1001][1001];

int solve(vector<vector<int>>& grid,int i,int j){
    int ans=1;
    if(t[i][j]!=-1)
        return t[i][j];
    for(int k=0;k<4;k++){
        int ni=i+dr[k];
        int nj=j+dc[k];
        if(ni>=0 && ni<m && nj>=0 && nj<n && grid[i][j]>grid[ni][nj]){
            ans=max(ans,1+solve(grid,ni,nj));
        }
    }
    return t[i][j]=ans;

}
    int longestIncreasingPath(vector<vector<int>>& grid) {
         m=grid.size();
         n=grid[0].size();
         memset(t,-1,sizeof(t));
         int result=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                result=max(result,solve(grid,i,j));
            }
        }
        return result;
    }
};