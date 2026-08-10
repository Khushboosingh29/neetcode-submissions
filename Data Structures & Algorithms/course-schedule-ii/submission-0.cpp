class Solution {
public:

vector<int> solve(unordered_map<int,vector<int>> &adj,int n,vector<int> &indegree)
{
    int cnt=0;
    queue<int>q;
    vector<int>res;
    for(int i=0;i<n;i++){
        if(indegree[i]==0)
        {
            res.push_back(i);
            q.push(i);
            cnt++;
         }
    }

         while(!q.empty()){
            auto m=q.front();
            q.pop();
        
            for(auto e:adj[m])
            {
                indegree[e]--;
                if(indegree[e]==0)
                    {
                        res.push_back(e);
                        q.push(e);
                        cnt++;
                    }

            }
         }
    
    if(cnt==n)
        return res;
    return {};

}
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
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

