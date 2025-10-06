class Solution {
  public:
    
    bool isSafe(int row, int col, vector<vector<int>> &board, int num){
        for(int i=0;i<9;i++){
        if(board[row][i] == num || board[i][col] == num){
            return false;
        }
        int subrow = 3 * (row/3) + i/3;
        int subcol = 3 * (col/3) + i%3;
        if(board[subrow][subcol] == num)
            return false;
      }   
      return true;
    }
    // Function to find a solved Sudoku.
    bool solve(vector<vector<int>> &board) {
        // code here
        for(int row = 0; row<9;row++){
            for(int col =0;col<9;col++){
                if(board[row][col] == 0) {
                    for(int num = 1;num<=9;num++){
                        if(isSafe(row,col,board,num)) {
                            board[row][col] = num;
                            
                            if(solve(board)){
                                return true;
                            }
                            board[row][col] =0;
                            
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    } 
        
        void solveSudoku(vector<vector<int>> &mat){
            solve(mat);
        }
};
