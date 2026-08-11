class Solution {
public:
vector<vector<int>>dr={{0,1},{-1,0},{0,-1},{1,0}};
int m,n;
void dfs(vector<vector<int>>& heights,int r,int c,int prev,vector<vector<int>>&vis){
    if(r<0 || r>=m || c<0 || c>=n || vis[r][c] || heights[r][c]<prev)
        return;
    vis[r][c]=true;
    for(int i=0;i<4;i++){
        int nr=r+dr[i][0];
        int nc=c+dr[i][1];
        dfs(heights,nr,nc,heights[r][c],vis);
    }

}
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
         m=heights.size();
         n=heights[0].size();

        vector<vector<int>>pvis(m,vector<int>(n,0));
        vector<vector<int>>avis(m,vector<int>(n,0));
        vector<vector<int>>res;
        for(int j=0;j<n;j++){
            dfs(heights,0,j,INT_MIN,pvis);
            dfs(heights,m-1,j,INT_MIN,avis);
        }

        for(int i=0;i<m;i++){
            dfs(heights,i,0,INT_MIN,pvis);
            dfs(heights,i,n-1,INT_MIN,avis);
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(pvis[i][j] && avis[i][j])
                    res.push_back({i,j});
            }
        }
        return res;
    }
};
