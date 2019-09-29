/*
Alternate positive and negative elements
Given an array of integers A, arrange them in an alternate fashion such that every non-negative number is followed by negative and vice-versa, starting from a negative number, maintaining the order of appearance. The number of non-negative and negative numbers need not be equal. If there are more non-negative numbers they appear at the end of the array. If there are more negative numbers, they too appear at the end of the array. Note: Try solving with O(1) extra space. 
Input Format
The first argument given is the integer array A.
Output Format
Return the modified array.
Constraints
1 <= length of the array <= 7000
-10^9 <= A[i] <= 10^9 
For Example
Input 1:
    A = [-1, -2, -3, 4, 5]
Output 1:
    [-1, 4, -2, 5, -3]

Input 2:
    A = [5, -17, -100, -11]
Output 2:
    [-17, 5, -100, -11]
*/

//Try solving in O(1) space complexity

vector<int> Solution::solve(vector<int> &A) {
    vector<int > neg, pos, res;
    for(int i=0;i<A.size();i++){
        if(A[i]<0){
            neg.push_back(A[i]);
        }else{
            pos.push_back(A[i]);
        }
    }
    
    int flagp=0, flagn=0, p=pos.size(), n=neg.size();
    if(n>p){
        int j=0;
        for(int i=0;i<n;i++){
            res.push_back(neg[i]);
            if(j<p){
                res.push_back(pos[j]);
                j++;
            }
        }
    }else{
        int j=0;
        for(int i=0;i<p;i++){
            if(j<n){
                res.push_back(neg[j]);
                j++;
            }
            res.push_back(pos[i]);
        }
    }
    return res;
}