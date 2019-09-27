/*
Minimum swaps required to bring all elements less than or equal to k together
Given an array of integers A and an integer B, find and return the minimum number of swaps required to bring all the numbers less than or equal to B together. Note: It is possible to swap any two elements, not necessarily consecutive.
Input Format
The first argument given is the integer array A.
The second argument given is the integer B.
Output Format
Return the minimum number of swaps.
Constraints
1 <= length of the array <= 100000
-10^9 <= A[i], B <= 10^9
For Example
Input 1:
    A = [1, 12, 10, 3, 14, 10, 5]
    B = 8
Output 1:
    2

Input 2:
    A = [5, 17, 100, 11]
    B = 20
Output 2:
    1
*/

//Classic sliding window problem
int Solution::solve(vector<int> &A, int B) {
    int count=0, bad=0, good=0;
    int n=A.size();
    for(int i=0;i<n;i++){ //Count all the numbers which are needed to be aligned (i.e less than equal to B)
        if(A[i]<=B)
            good++;
    }
    for(int i=0;i<good;i++){ // First window, take bad count (i.e element > B)
        if(A[i]>B)
            bad++;
    }
    count=bad; //count became bad val
    for(int i=good;i<n;i++){ // Check bad count for all next windows and min of count of first window and all other windows would be min swaps required
        if(A[i]>B)
            bad++;
        if(A[i-good]>B) // If previous remove count of previous window, so we consider only current windows
            bad--;
        count=std::min(bad, count);
    }
    return count;
}
