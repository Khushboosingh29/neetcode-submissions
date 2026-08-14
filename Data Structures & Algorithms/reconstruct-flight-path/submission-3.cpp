class Solution {
public:
unordered_map<string,vector<string>>adj;
vector<string> result;
int numt=0;


void dfs(const string& airport) {
        auto& destinations = adj[airport];
        while (!destinations.empty()) {
            string next = destinations.back();
            destinations.pop_back(); // O(1) removal
            dfs(next);
        }
        result.push_back(airport); // Post-order collection
    }

vector<string> findItinerary(vector<vector<string>>& tickets) {
      numt=tickets.size();  
        for(auto &t:tickets){
            string u=t[0];
            string v=t[1];
            adj[u].push_back(v);
        }

        for(auto &edges:adj){
                sort(edges.second.rbegin(), edges.second.rend());
        }

    
        dfs("JFK");
        reverse(result.begin(), result.end());
        return result;
        
    }
};
