/*
Sum of all Submatrices
Given a 2D Matrix of dimensions N*N, we need to return sum of all possible submatrices. Example Input
[ [1,1],
  [1,1] ]
Example Output
16
Explanation
Number of submatrices with 1 elements = 4, so sum of all such submatrices = 4*1 = 4
Number of submatrices with 2 elements = 4, so sum of all such submatrices = 4*2 = 8
Number of submatrices with 3 elements = 0
Number of submatrices with 4 elements = 1, so sum of such submatrix = 4

Total Sum = 4+8+4 = 16
*/

int Solution::solve(vector<vector<int> > &A) { 
    //Logic is to find sum of each cell, which in turn would be the value of cell * no of times the cell appears in all sub matrices
    int n=A.size();
    vector<int> res;
    for(int i=0;i<n;i++){
        for(int j=0;j<A[i].size();j++){
            int sum=0;
            sum+=A[i][j] * ((i+1)*(j+1) * (n-i)*(n-j));
            res.push_back(sum);
        }
    }
    int val=0;
    for(auto a: res){
        val+=a;
    }
    return val;
}
