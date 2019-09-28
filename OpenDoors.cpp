/*
Number Of Open Doors
Given an integer A which denotes the number of doors in a row numbered 1 to A. All the doors are closed initially. A person moves to and fro changing the states of the doors as follows: the person opens a door that is already closed and closes a door that is already opened. In the first go, the person alters the states of doors numbered 1, 2, 3, … , A. In the second go, she alters the states of doors numbered 2, 4, 6 … In the third go, she alters the states of doors numbered 3, 6, 9 … This continues till the A'th go in which you alter the state of the door numbered A. Find and return the number of open doors at the end of the procedure. 
Input Format
The only argument given is integer A.
Output Format
Return the number of open doors at the end of the procedure.
Constraints
1 <= A <= 10^9
For Example
Input 1:
    A = 10
Output 1:
    3

Input 2:
    A = 20
Output 2:
    4

*/

// Logic is to find numbers which would have odd number of factor i.e. perfect square and the number of perfect square in range 1 to n is sqrt(n)

int Solution::solve(int A) {
    return sqrt(A);
}
