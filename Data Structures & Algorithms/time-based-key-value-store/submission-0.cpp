class TimeMap {
public:
unordered_map<string,vector<pair<int,string>>>mpp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mpp[key].push_back({timestamp,value});
        
    }
    
    string get(string key, int timestamp) {
        if(mpp.find(key)==mpp.end())
            return "";
        vector<pair<int, string>> val=mpp[key];
        int l=0;
        int r=val.size()-1;
        string res="";   
        while(l<=r)  {
            int mid=l+(r-l)/2;
            if(val[mid].first<=timestamp){
                res=val[mid].second;
                l=mid+1;

            }
            else
                r=mid-1;
        } 
        return res;  
    }
};
