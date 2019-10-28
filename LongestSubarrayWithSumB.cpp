/*
Longest Subarray Sum B
Given an array of integers A of size N and an integer B. Find the length of longest subarray having sum equal to B. If no such subarray exists then return -1. 
Input Format
The First argument given is the integer array A.
The Second argument is an integer B.
Output Format
Return the length of longest subarray having sum equal to B if exists else return -1.
Constraints
1 <= N <= 100000
-10^6 <= A[i] <= 10^6
-10^9 <= B <= 10^9
For Example
Input 1:
    A = [1, 2, 3, 4, 5]
    B = 10

Output 1:
    4

Input 2:
    A = [1, -1, -1, 1]
    B = 0
Output 2:
    4
*/

int Solution::solve(vector<int> &A, int B) {
    
    unordered_map<int, int> um; 
    int sum = 0, maxLen = -1; 
  
    for (int i = 0; i < A.size(); i++) { 
        sum += A[i]; 
        if (sum == B) 
            maxLen = i + 1; 
        if (um.find(sum) == um.end())  // if sum doesnt exist make entry with mp[sum]=i
            um[sum] = i; 
        if (um.find(sum - B) != um.end()) { //search for sum-k
            if (maxLen < (i - um[sum - B])) 
                maxLen = i - um[sum - B];
        } 
    } 
    return maxLen; 
}
