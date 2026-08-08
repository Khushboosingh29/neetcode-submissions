class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        int fresh=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2)
                    q.push({i,j});
                else if(grid[i][j]==1)
                    fresh++;
            }
        }
        if(fresh==0)
            return 0;
        int time=0;

        while(!q.empty())
        {
            int s=q.size();
            while(s--){
                auto curr=q.front();
                q.pop();
                int i=curr.first;
                int j=curr.second;
                vector<vector<int>>dr{{0,1},{-1,0},{0,-1},{1,0}};
                for(int k=0;k<4;k++){
                    int  ni=i+dr[k][0];
                    int nj=j+dr[k][1];
                    if(ni>=0 &&  ni<n && nj>=0 && nj<m && grid[ni][nj]==1)
                      {  
                        q.push({ni,nj});
                        grid[ni][nj] = 2;
                        fresh--;
                      }
                    
                }

            }
            time++;        
            
        }  
        return fresh==0? time-1:-1;  
    }
};
