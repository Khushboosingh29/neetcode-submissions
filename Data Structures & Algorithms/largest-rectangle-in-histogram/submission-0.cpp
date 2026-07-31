class Solution {
public:
    vector<int> pse(vector<int>& heights){
    int n=heights.size();
    vector<int>res(n,-1);
    stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()] >= heights[i])
                st.pop();
            if(!st.empty())
                res[i]=st.top();

            

            st.push(i);
        }
        return res;

}
vector<int>  nse(vector<int>& heights){
    int n=heights.size();
    vector<int>res1(n,n);
    stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()] >= heights[i])
                st.pop();
            if(!st.empty())
                res1[i]=st.top();

          

            st.push(i);
        }
        return res1;
}

    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        int maxi=INT_MIN;
        vector<int>gpse=pse(heights);
        vector<int>gnse=nse(heights);
        for(int i=0;i<n;i++){

            maxi=max(maxi,heights[i]*(gnse[i]-gpse[i]-1));
        }
        return maxi;

        
    } 
    
};
