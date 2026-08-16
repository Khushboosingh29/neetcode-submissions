class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        priority_queue<pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>>pq;

        vector<vector<bool>>vis(n,vector<bool>(n,false));
        vector<int>dr={0,-1,0,1};
        vector<int>dc={1,0,-1,0};
        pq.push({grid[0][0],{0,0}});
        vis[0][0]=true;
        while(!pq.empty()){
            int time=pq.top().first;
            int i=pq.top().second.first;
            int j=pq.top().second.second;
            pq.pop();
            if(i==n-1 && j==n-1)
                return time;
            for(int k=0;k<4;k++){
               int  ni=i+dr[k];
               int  nj=j+dc[k];

                if(ni>=0 && ni<n && nj>=0 && nj<n && !vis[ni][nj]){
                    vis[ni][nj]=true;
                    int maxt=max(grid[ni][nj],time);
                    pq.push({maxt,{ni,nj}});

                    }
            }

        }
        return 0;
        
    }
};
