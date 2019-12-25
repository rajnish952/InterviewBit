/*
Unique Paths in a Grid
Given a grid of size m * n, lets assume you are starting at (1,1) and your goal is to reach (m,n). At any instance, if you are on (x,y), you can either go to (x, y + 1) or (x + 1, y). Now consider if some obstacles are added to the grids. How many unique paths would there be? An obstacle and empty space is marked as 1 and 0 respectively in the grid. Example : There is one obstacle in the middle of a 3x3 grid as illustrated below.
[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.
*/

//The Intution behind is if a path is valid i.e. no obstacle to reach (i,j)th position we need sum of path to reach (i-1, j) + (i, j-1) paths

int Solution::uniquePathsWithObstacles(vector<vector<int> > &A) {
    
    int m=A.size();
    int n=A[0].size();
    int arr[m][n];
    
    
    if(A[0][0]==1)
        return 0;
    
    arr[0][0]=1;
    for(int i=1;i<n;i++){
        arr[0][i]=(A[0][i]==0 && arr[0][i-1]>0) ? 1 : 0; // In a row, if there is obstacle remaining row would have 0 val
    }
    for(int j=1;j<m;j++){
        arr[j][0]=(A[j][0]==0 && arr[j-1][0]>0) ? 1 : 0; // In a col, if there is obstacle remaining row would have 0 val
    }
    
    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            arr[i][j]=(A[i][j] == 1 ? 0 : arr[i - 1][j] + arr[i][j - 1]); // if current value is obstacle return 0, else sum of values
        }
    }
    
    return arr[m-1][n-1];
}