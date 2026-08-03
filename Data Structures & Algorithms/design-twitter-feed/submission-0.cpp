class Twitter {
    map<int,set<int>>friends;
    int curr=0;
    priority_queue<vector<int>>timeline;
public:
    Twitter() {
        friends.clear();
        curr=0;
        timeline=priority_queue<vector<int>>();
    }
    
    void postTweet(int userId, int tweetId) {
        timeline.push({curr++,userId,tweetId});
        
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int>ans;
        priority_queue<vector<int>>userT=timeline;
        int n=0;
        while(!userT.empty() && n<10){
            auto tweet=userT.top();
            userT.pop();
            int time = tweet[0];
            int posterId = tweet[1];
            int tId = tweet[2];
            if(posterId==userId || friends[userId].count(posterId)){
                ans.push_back(tId);
                n++;
            }

        }
       return ans; 
    }
    
    void follow(int followerId, int followeeId) {
        if( followerId!=followeeId)
         friends[followerId].insert(followeeId);
        
    }
    
    void unfollow(int followerId, int followeeId) {
        if(friends.count(followerId))
          friends[followerId].erase(followeeId);
    }
};
