class Solution {
public:
bool isvalid(vector<vector<char>>&board,int i,int er,int j,int ec){
     unordered_set<int>st;
     for(int row=i;row<=er;row++){
           
            for(int col=j;col<=ec;col++){
                if(board[row][col]=='.')
                    continue;
                if(st.find(board[row][col])!=st.end())
                    return false;
                st.insert(board[row][col]);

            }
        }
        return true;

}
    bool isValidSudoku(vector<vector<char>>& board) {

        for(int row=0;row<9;row++){
            unordered_set<int>st;
            for(int col=0;col<9;col++){
                if(board[row][col]=='.')
                    continue;
                if(st.find(board[row][col])!=st.end())
                    return false;
                st.insert(board[row][col]);

            }
        }
            for(int col=0;col<9;col++){
            unordered_set<int>st;
            for(int row=0;row<9;row++){
                if(board[row][col]=='.')
                    continue;
                if(st.find(board[row][col])!=st.end())
                    return false;
                st.insert(board[row][col]);

            }
        }
         for(int i=0;i<9;i+=3){
               int er=i+2;
            for(int j=0;j<9;j+=3){
               int ec=j+2;
               if(!isvalid(board,i,er,j,ec))
                    return false;

            }
         }


       return true;  
    }
};
