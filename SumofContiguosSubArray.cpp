/*
Find sub-array with the given sum
Given an array of positive integers A and an integer B, find and return first continuous subarray which adds to B. If the answer does not exist return an array with a single element "-1". Note: First sub-array means the sub-array for which starting index in minimum.
Input Format
The first argument given is the integer array A.
The second argument given is integer B.
Output Format
Return the first continuous sub-array which adds to B and if the answer does not exist return an array with a single element "-1".
Constraints
1 <= length of the array <= 100000
1 <= A[i] <= 10^9
1 <= B <= 10^9
For Example
Input 1:
    A = [1, 2, 3, 4, 5]
    B = 5
Output 1:
    [2, 3]

Input 2:
    A = [5, 10, 20, 100, 105]
    B = 110
Output 2:
    [-1]
    */

vector<int> Solution::solve(vector<int> &A, int B) {
    vector<int> res;
    int i=0,j=0, sum=A[i];
    while(i<=j && j<A.size()){ //Two pointer to check
        if(sum<B){ //if sum < B, increment j
            j++;
            if(j<A.size()) // and if j<n, corner case add A[j] to sum
                sum+=A[j];
        }
        if(sum>B){ // Else increment i, which reduces the window and reduce the sum
            sum-=A[i];
             i++;
        }
        if(sum==B)
        {
            for(int k=i;k<=j;k++) // simply push to vector
                res.emplace_back(A[k]);
            return res;
        }
    }
    return {-1};
}
