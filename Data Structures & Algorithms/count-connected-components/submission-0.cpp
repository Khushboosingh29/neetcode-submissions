class Solution {
public:
void dfs(int node, vector<vector<int>> &adj, vector<int> &vis){
    vis[node]=1;
    for(auto n:adj[node]){
        if(vis[n]==0)
            {
                dfs(n,adj,vis);
            }
    }
}
    int countComponents(int n, vector<vector<int>>& edges) {

        vector<vector<int>> adj(n);
        for(auto e:edges){
            int u=e[0];
            int v=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>vis(n,0);
        int cnt=0;
        for(int i=0;i<n;i++){

            if(vis[i]==0)
            {
                dfs(i,adj,vis);
                cnt++;
            }

        }
    return cnt;
    }
};
