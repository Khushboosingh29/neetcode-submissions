class Solution {
public:

int dfs(vector<vector<int>>& grid,int i,int j,int n,int m){
    if(i<0 || i>=n || j<0 ||j>=m || grid[i][j]!=1)
        return 0;
    grid[i][j]=0;
   
    
    return 1+dfs(grid,i+1,j,n,m)+
    dfs(grid,i,j-1,n,m)+
    dfs(grid,i-1,j,n,m)+
    dfs(grid,i,j+1,n,m);
    

}
 
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        int n=grid.size();
        int m=grid[0].size();
        int maxi=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                   int cnt= dfs(grid,i,j,n,m);
                    maxi=max(maxi,cnt);
                    
                }
            }

        }
        return maxi;
        
    }
};
