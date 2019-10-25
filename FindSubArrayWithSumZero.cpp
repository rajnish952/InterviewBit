/*
Find if there is a sub-array with 0 sum
Given an array of integers A, find and return whether the given array contains a subarray with a sum equal to 0. If the given array contains a sub-array with sum zero return 1 else return 0. Note: Length of sub array should be at least one. 
Input Format
The only argument given is the integer array A.
Output Format
Return whether the given array contains a subarray with a sum equal to **0**.
Constraints
1 <= length of the array <= 100000
-10^9 <= A[i] <= 10^9 
For Example
Input 1:
    A = [1, 2, 3, 4, 5]
Output 1:
    0

Input 2:
    A = [5, 17, -22, 11]
Output 2:
    1
    */


// Take prefix sum and check if prefix array has either zero or two same values, return true in that case else false

int Solution::solve(vector<int> &A) {

    unordered_set<long long> sumSet; 
  
    long long sum = 0; 
    for (int i = 0 ; i < A.size() ; i++) 
    { 
        sum += A[i]; 
  
        if (sum == 0 || sumSet.find(sum) != sumSet.end()) 
            return 1; 
  
        sumSet.insert(sum); 
    } 
    return 0; 
}
