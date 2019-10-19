/*
NQueens
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other. N Queens: Example 1 Given an integer n, return all distinct solutions to the n-queens puzzle. Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively. For example, There exist two distinct solutions to the 4-queens puzzle:
[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
*/

bool isSafe( vector<string>& board, int row, int col ){
int A = board.size();
for( int i=0; i<A; i++ ){ // safe in row
   
    if( board[i][col]  == 'Q')
        return false;
}

for( int j=0; j<A; j++ ){ // safe in col
    
    if( board[row][j]  == 'Q')
        return false;
}

for( int i=row, j=col; i>=0 && j>=0; i--, j-- ){ // safe in left 
    
    if( board[i][j] == 'Q' )
        return false;
}

for( int i=row, j=col; i>=0 && j<A; i--, j++ ){ // check right diagonal
    
    if( board[i][j] == 'Q')
        return false;
}

return true;
}

void nqueen(vector<string> &row, vector<vector<string> > &res, int l){
    if(l==row.size()){ // when l i.e. cuurent_idx = row.size() push vector in result
        res.emplace_back(row);
        return;
    }
    
    for(int i=0; i<row.size(); i++){ // for each row i=0, till n
        if (isSafe (row, l, i)) // check if the location is safe i.e l, i 
        {
            row [l][i] = 'Q'; // if safe place queen
            nqueen (row, res, l+1); // check next index 
            row [l][i] = '.'; // revert queen to original state
        }
    }
}

vector<vector<string> > Solution::solveNQueens(int A) {
    
    vector <vector <string>> res;
    vector <string> row;
    
    string r;
    
    for (int i = 0; i < A ;i++) // String of "."
        r+='.'; 
        
    for (int i = 0; i < A ;i++) // Vector with all value "."
        row.push_back (r); 
    
    nqueen (row, res, 0);
    
    return res;
}
