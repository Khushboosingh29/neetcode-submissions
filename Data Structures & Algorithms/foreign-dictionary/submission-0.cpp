class Solution {
public:
string toposort(int v, unordered_map<char, unordered_set<char>>& adj, unordered_map<char, int>& inDegree) {
        queue<char> q;
        for (auto& [ch, degree] : inDegree) {
            if (degree == 0) {
                q.push(ch);
            }
        }

        string order = "";
        while (!q.empty()) {
            char curr = q.front();
            q.pop();
            order += curr;

            for (char neighbor : adj[curr]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

    
        if (order.size() < v) {
            return "";
        }

        return order;
    }
    string foreignDictionary(vector<string>& words) {
        int n=words.size();
        unordered_map<char, unordered_set<char>> adj;
        unordered_map<char, int> inDegree;


        for (const string& w : words) {
            for (char c : w) {
                if (!adj.count(c)) {
                    adj[c] = unordered_set<char>();
                    inDegree[c] = 0;
                }
            }
        }
        
        for(int i=0;i<n-1;i++){
            string w1=words[i];
            string w2=words[i+1];
            int len=min(w1.size(),w2.size());
            bool diffFound = false;
            for(int k=0;k<len;k++){
                if(w1[k]!=w2[k]){
                    if (!adj[w1[k]].count(w2[k])) {
                        adj[w1[k]].insert(w2[k]);
                        inDegree[w2[k]]++;
                    }
                    diffFound = true;
                    break;
                }
            }
            // Prefix invalid check: e.g., ["abcd", "ab"]
            if (!diffFound && w1.size() > w2.size()) {
                return "";
            }
        }
        int v=adj.size();
        return toposort(v,adj,inDegree);
        
    }
};
