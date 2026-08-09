class Solution {
public:
int n;
int m;
vector<int>dr{0,-1,0,+1};
vector<int>dc{+1,0,-1,0};
void dfs(int r,int c,vector<vector<char>>& board,vector<vector<int>> &vis){
    vis[r][c]=1;
    for(int i=0;i<4;i++){
        int nr=r+dr[i];
        int nc=c+dc[i];
        if(nr>=0 && nr<n && nc>=0  && nc<m && board[nr][nc]=='O' &&  !vis[nr][nc]){
            dfs(nr,nc,board,vis);
        }
    }
}

    void solve(vector<vector<char>>& board) {
         n=board.size();
         m=board[0].size();
         vector<vector<int>>vis(n,vector<int>(m,0));
         for(int j=0;j<m;j++){
            if(board[0][j]=='O' && !vis[0][j])
                dfs(0,j,board,vis);
            if(board[n-1][j]=='O' && !vis[n-1][j])
                dfs(n-1,j,board,vis);
         }
          for(int i=0;i<n;i++){
            if(board[i][0]=='O' && !vis[i][0])
                dfs(i,0,board,vis);
            if(board[i][m-1]=='O' && !vis[i][m-1])
                dfs(i,m-1,board,vis);
         }

         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O' && !vis[i][j])
                    board[i][j]='X';
            }
         }
        
    }
};
