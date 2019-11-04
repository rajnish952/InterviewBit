/*
Maximum Difference
Given an array of integers A and an integer B. Find and return the maximum value of | s1 - s2 | where s1 = sum of any subset of size B, s2 = sum of elements of A - sum of elemets of s1 Note |x| denotes the absolute value of x. 
Input Format
The arguments given are the integer array A and integer B.
Output Format
Return the maximum value of | s1 - s2 |.
Constraints
1 <= B < length of the array <= 100000
1 <= A[i] <= 10^5 
For Example
Input 1:
    A = [1, 2, 3, 4, 5]
    B = 2
Output 1:
    9

Input 2:
    A = [5, 17, 100, 11]
    B = 3
Output 2:
    123
*/

// Sort and take full sum, now s1=sum till b elments and s2 is sum from B till last elements

int Solution::solve(vector<int> &A, int B)
{

    long long int pre = 0, suf = 0, sum = 0;
    sort(A.begin(), A.end());

    for (auto a : A)
    {
        sum += a;
    }

    int temp = 0;
    for (int i = 0; i < B; i++)
    { // To calculate S1
        pre += A[i];
    }
    for (int i = A.size() - B; i < A.size(); i++) // To calculate S2
    {
        suf += A[i];
    }

    return max(llabs(sum - 2 * pre), llabs(sum - 2 * suf)); // abs max of values
}
