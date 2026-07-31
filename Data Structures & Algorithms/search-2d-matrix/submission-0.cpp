class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r=matrix.size();
        int c=matrix[0].size();
        for(int i=0;i<r;i++)
        {
            int l=0;
            int r=c-1;
            while(l<=r){
                int mid=l+(r-l)/2;
                if(matrix[i][mid]==target)
                    return true;
                else if(matrix[i][mid]<target)
                    l=mid+1;
                else
                    r=mid-1;
            }
        }
        return false;
    }
};
