/*
Longest Common Subsequence
Given two strings A and B. Find the longest common sequence ( A sequence which does not need to be contiguous), which is common in both the strings. You need to return the length of such longest common subsequence. NOTE:
Your code will be run on multiple test cases (<=10). Try to come up with an optimised solution.
CONSTRAINTS
1 <= Length of A, B <= 10^3 + 5
EXAMPLE INPUT
A : "abbcdgf"
B : "bbadcgf"
EXAMPLE OUTPUT
5
EXPLANATION
The longest common subsequence is "bbcgf", which has a length of 5
*/

// The intution is to check from the end of string, if last elements match then the LCS=1+LCS(i-1, j-1) else max(LCS(i-1,j), LCS(i,j-1))

int Solution::solve(string A, string B) {
    int row=A.length();
    int col=B.length();
    
    int dp[row+1][col+1];
    for(int i=0;i<=row;i++){
        for(int j=0;j<=col;j++){
            if(i==0 || j==0){ // if first row or col, consider it LCS with empty string and so val=0
                dp[i][j]=0;
            }
            else if(A[i-1]==B[j-1]){ // Build bottom to up matrix, because we are considering an added empty string befor the actual string so A[0] becomes A[1]
                dp[i][j]=1+dp[i-1][j-1];
            }else{
                dp[i][j]=std::max(dp[i-1][j], dp[i][j-1]); // if elements are not equal take max of row and col
            }
        }
    }
    return dp[row][col]; // return last element in matrix as result
}
