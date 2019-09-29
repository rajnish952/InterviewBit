/*
Finding Position
Given an integer A which denotes the number of people standing in the queue. A selection process follows a rule where people standing on even positions are selected. Of the selected people a queue is formed and again out of these only people on even position are selected. This continues until we are left with one person. Find and return the position of that person in the original queue. 
Input Format
The only argument given is integer A.
Output Format
Return the position of the last selected person in the original queue.
Constraints
1 <= A <= 10^9
For Example
Input 1:
    A = 10
Output 1:
    8

Input 2:
    A = 20
Output 2:
    16
*/

//The idea is to get power of two less then N, which would be the number which remains at the end

int Solution::solve(int A) {
    int p=int(log2(A));
    return pow(2,p);
}
