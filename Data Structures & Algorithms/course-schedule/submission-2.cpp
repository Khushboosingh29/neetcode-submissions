class Solution {
public:
bool solve( unordered_map<int,vector<int>> &adj,int n, vector<int> &indegree){
    int cnt=0;
    queue<int>q;
    for(int i=0;i<n;i++){
        if(indegree[i]==0)
        {
            q.push(i);
         }
    }

         while(!q.empty()){
            auto m=q.front();
            q.pop();
            cnt++;
            for(auto e:adj[m])
            {
                indegree[e]--;
                if(indegree[e]==0)
                    {
                        q.push(e);
        
                    }

            }
         }
    
    if(cnt==n)
        return true;
    return false;

}
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        unordered_map<int,vector<int>>adj;
        vector<int>indegree(numCourses,0);
        for(auto p:prerequisites)
        {
            int u=p[0];
            int v=p[1];

            adj[v].push_back(u);
            indegree[u]++;
         }
         return solve(adj,numCourses,indegree);
        
    }
};
