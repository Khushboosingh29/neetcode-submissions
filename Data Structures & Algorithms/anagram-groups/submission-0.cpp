class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        vector<vector<string>> res;
        unordered_map<string,vector<string>>mpp;
        for(int i=0;i<strs.size();i++){
            string word=strs[i];
            sort(word.begin(),word.end());
            mpp[word].push_back(strs[i]);
        }
        for(auto it:mpp){
            res.push_back(it.second);
        }
        return res;
    }
};
