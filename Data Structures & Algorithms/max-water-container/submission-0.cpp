class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n=heights.size();
        int i=0;
        int j=n-1;
        int maxi=0;
        while(i<j){
            int dis=j-i;
            int ar=dis*min(heights[i],heights[j]);
            maxi=max(maxi,ar);
         
            if (heights[i] < heights[j]) {
                i++; 
            } else {
                j--;
            }

        }
        return maxi;
    }
};
