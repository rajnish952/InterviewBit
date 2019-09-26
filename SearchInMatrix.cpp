/*
Given a matrix of integers A of size N x M and an integer B. In the given matrix every row and column is sorted in increasing order. Find and return the position of B in the matrix in the given form:
If A[i][j] = B then return (i * 1009 + j)
And if B is not present return -1 instead. Note: Rows are numbered from top to bottom and columns are numbered from left to right. 
Input Format
The first argument given is the integer matrix A.
The second argument given is the integer B.
Output Format
Return the position of B and if it is not present in A return -1 instead.
Constraints
1 <= N, M <= 1000
-100000 <= A[i] <= 100000
-100000 <= B <= 100000
For Example
Input 1:
    A = [   [1, 2, 3]
            [4, 5, 6]
            [7, 8, 9]   ]
    B = 2
Output 1:
    1011    (= 1 * 1009 + 2)

Input 2:
    A = [   [1, 3, 5, 7]
            [2, 4, 6, 8]    ]
    B = 10
Output 2:
    -1
    */

int Solution::solve(vector<vector<int> > &A, int B) {
    
    for(int i=0;;){
        for(int j=A[i].size()-1;;){ //start from top right go towards bottom left
            
            if(i==A.size() || j==-1)
                return -1;
            
            if(A[i][j]==B)
                return ((i+1)*1009 + (j+1));
            else if(A[i][j]>B)
                j--;
            else
                i++;
        }
    }
    
}