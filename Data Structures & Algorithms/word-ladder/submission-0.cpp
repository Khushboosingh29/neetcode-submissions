class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st(wordList.begin(),wordList.end());
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        st.erase(beginWord);
        while(!q.empty()){
            auto curr=q.front();
            string word=curr.first;
            int level=curr.second;
            q.pop();
            if(word==endWord)
                return level;
            for(int i=0;i<word.size();i++){
                char w=word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(st.find(word)!=st.end()){
                        q.push({word,level+1});
                        st.erase(word);
                    }


                }
                word[i]=w;
            }

        }
        return 0;
    }
};
