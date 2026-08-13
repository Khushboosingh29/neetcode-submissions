class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        unordered_map<int,vector<pair<int,int>>>adj;
        vector<int>dist(n,INT_MAX);
        for(auto vec:flights){
            int u=vec[0];
            int v=vec[1];
            int w=vec[2];

            adj[u].push_back({v,w});
        }

        queue<pair<int,int>>q;
        q.push({src,0});
        dist[src]=0;
        int steps=0;

        while(!q.empty() && steps<=k){
            
            int n=q.size();
            while(n--){
                int node=q.front().first;
                int d=q.front().second;
                q.pop();

                for(auto n:adj[node]){
                    int adjn=n.first;
                    int cost=n.second;
                    if(dist[adjn]>d+cost){
                        dist[adjn]=d+cost;
                        q.push({adjn,d+cost});
                    }
                }
            }
            steps++;
        }
        return dist[dst]==INT_MAX?-1:dist[dst];
    }
};
