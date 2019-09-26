/*
Scooby has 3 three integers A, B and C. Scooby calls a positive integer special if it is divisible by B and it is divisible by C. You need to tell number of special integers less than or equal to A. Constraints:
1<=A,B,C<=1000000000
Input:
A positive integer A
A positive integer B
A positive integer C
Note:
Your code will run against multiple testcases
Output:
One integer corresponding to the number of special integers less than or equal to A.
Examples: Input:
12
3
2
Output:
2
Explanation:
The two integers divisible by 2 and 3 and less than or equal to 12 are 6,12.
*/

int gcd(int b,int c){
    if(c==0)
        return b;
    return gcd(c, b%c);
}
int Solution::solve(int A, int B, int C) {

    int lcm=(B*C)/gcd(B,C);
    return A/lcm;
}
