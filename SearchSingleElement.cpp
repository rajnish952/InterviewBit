/*
Single Element in a Sorted Array
Given a sorted array of integers A where every element appears twice except for one element which appears once, find and return this single element that appears only once. 
Input Format
The only argument given is the integer array A.
Output Format
Return the single element that appears only once.
Constraints
1 <= length of the array <= 100000
1 <= A[i] <= 10^9 
For Example
Input 1:
    A = [1, 1, 2, 2, 3]
Output 1:
    3

Input 2:
    A = [5, 11, 11, 100, 100]
Output 2:
    5
    */

// we have two conditions here, if mid elemnt is at even index or mid element is at odd index, based on that the search space changes
int Solution::solve(vector<int> &A) {
    
    int l=0,h=A.size(),m;
    while(l<h){
        m=(l+h)/2;
        if(m%2==0){
            if(A[m]==A[m+1]){
                l=m+2; //If elements are equal check right part
            }else{
              h=m; //else check left part including mid
            }
        }else{
            if(A[m]==A[m-1]){
                l=m+1;
            }else{
              h=m-1;
            }   
        }
        if(l==h){
            return A[l];
        }
    }
}

