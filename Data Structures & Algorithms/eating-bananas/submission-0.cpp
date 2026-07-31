class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1;
        int r=*max_element(piles.begin(),piles.end());
        int ans=0;
        while(l<=r)
        {
            int totalh=0;
            int mid=l+(r-l)/2;
            for(int p:piles){
                totalh+=(p+mid-1)/mid;
            }
            if(totalh<=h)
            {
                ans=mid;
                r=mid-1;
            }

        else
            l=mid+1;
        }
      return ans;  
    }
};
