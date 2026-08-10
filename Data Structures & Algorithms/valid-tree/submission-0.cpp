class Solution {
public:
void dfs(int node,vector<vector<int>> &adj,vector<bool> &vis,int &cnt){
    vis[node]=true;
    cnt++;
    for(auto n:adj[node]){
        if(!vis[n])
            dfs(n,adj,vis,cnt);
    }

}
 bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size()!=n-1)
            return false;
        vector<vector<int>>adj(n);
        for(auto e:edges){
            int u=e[0];
            int v=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool>vis(n,false);
        int cnt=0;

         dfs(0,adj,vis,cnt);

        return (cnt==n);
    }
};
