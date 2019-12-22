/*
Min Sum Path in Matrix
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.
 Note: You can only move either down or right at any point in time. 
Example :
Input : 

    [  1 3 2
       4 3 1
       5 6 1
    ]

Output : 8
     1 -> 3 -> 2 -> 1 -> 1
*/

// The intution behind is, min path (i,j)=min((i-1,j), (i, j-1))+A[i][j]

int Solution::minPathSum(vector<vector<int> > &A) {
    
    int m=A.size();
    int n=A[0].size();

    int arr[m][n];
    arr[0][0]=A[0][0]; // store first val
    for(int i=1;i<n;i++) // Assign row values
        arr[0][i]=arr[0][i-1]+A[0][i];
    
    for(int j=1;j<m;j++) // assign col values
        arr[j][0]=arr[j-1][0]+A[j][0];
    
    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            arr[i][j]=std::min(arr[i-1][j], arr[i][j-1]) + A[i][j]; // Intution
        }
    }
    return arr[m-1][n-1];
}
