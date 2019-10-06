/*
Find a peak element
Given an array of integers A, find and return the peak element in it. An array element is peak if it is NOT smaller than its neighbors. For corner elements, we need to consider only one neighbor. For example, for input array {5, 10, 20, 15}, 20 is the only peak element. Following corner cases give better idea about the problem.
1) If input array is sorted in strictly increasing order, the last element is always a peak element. 
For example, 5 is peak element in {1, 2, 3, 4, 5}.
2) If input array is sorted in strictly decreasing order, the first element is always a peak element. 
10 is the peak element in {10, 9, 8, 7, 6}.
Note: It is guranteed that the answer is unique. 
Input Format
The only argument given is the integer array A.
Output Format
Return the peak element.
Constraints
1 <= length of the array <= 100000
1 <= A[i] <= 10^9 
For Example
Input 1:
    A = [1, 2, 3, 4, 5]
Output 1:
    5

Input 2:
    A = [5, 17, 100, 11]
Output 2:
    100
×
*/

// Imaginging the graph for element, if the mid is in desc order i.e A[m] > A[m+1]
// Search space reduce to l->m as there must be one peak in the left subarray, similarly for asc order
// Search space would be m+1->l and when l==r return

int Solution::solve(vector<int> &A) {
    
    int l=0, r=A.size(), m;
    while(l<=r){
        m=(l+r)/2;
        if(A[m]>A[m+1]){
            r=m;
        }else{
            l=m+1;
        }
        if(l==r)
            return A[l];
    }
}
