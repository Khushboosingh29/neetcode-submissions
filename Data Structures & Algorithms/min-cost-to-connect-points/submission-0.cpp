
class Solution {
public:
int prims(vector<vector<pair<int,int>>>&adj,int v){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    vector<int>vis(v,0);
    pq.push({0,0});
    int sum=0;
    while(!pq.empty()){
        int wt=pq.top().first;
        int node=pq.top().second;
        pq.pop();
        if(vis[node])
            continue;
        vis[node]=1;
        sum+=wt;
        for(auto n:adj[node])
        {
           int adjn=n.first;
           int d=n.second; 
           if(vis[adjn]!=1)
            pq.push({d,adjn});
        }
    }
return sum;
}
    int minCostConnectPoints(vector<vector<int>>& points) {
        int v=points.size();
        vector<vector<pair<int,int>>>adj(v);

        for(int i=0;i<v;i++){
            for(int j=i+1;j<v;j++){
                int x1=points[i][0];
                int y1=points[i][1];
                int x2=points[j][0];
                int y2=points[j][1];
                int dis=abs(x1-x2) + abs(y1-y2);

                adj[i].push_back({j,dis});
                adj[j].push_back({i,dis});
            }
        }
        return prims(adj,v);
    }
};