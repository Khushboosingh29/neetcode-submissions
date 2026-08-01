class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;

 vector<vector<int>>ans;
for(auto point:points)
{
    int x=point[0];
    int y=point[1];
    int dis=((y-0)*(y-0)+(x-0)*(x-0));
    pq.push({dis,{x,y}});
    }
    while(k!=0 && !pq.empty())
    {
    auto pt=pq.top().second;
    ans.push_back({pt.first,pt.second});
    pq.pop();
    k--;
  
    }
    return ans;
    }
};
