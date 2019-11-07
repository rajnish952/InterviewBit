/*
Reverse a stack using recursion
Given a stack of integers A. You are required to reverse the stack using recursion. You are not allowed to use loop constructs like while, for..etc, Return A after reversing it using recursion. NOTE: It is mandatory to reverse A using recursion. 
Input Format
The only argument given is the integer array A.
Output Format
Return the reversal of A using stack.
Constraints
1 <= length of the array <= 2000
1 <= A[i] <= 10^8 
For Example
Input 1:
    A = [1, 5, 3, 2, 4]
Output 1:
    [4, 2, 3, 5, 1]

Input 2:
    A = [5, 17, 100, 11]
Output 2:
    [11, 100, 17, 5]
*/

void reverse_stack(vector<int> s, vector<int> &res, int top){
    if(top==s.size())
        return;
    int temp=s[top];
    reverse_stack(s, res, ++top);
    res.push_back(temp);
}
vector<int> Solution::solve(vector<int> &A) {

    vector<int > res;
    int top=0;
    reverse_stack(A, res, top);
    return res;
}
