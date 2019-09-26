/*
Enumerating GCD
You are given a number P and a number Q. Greatest Common Divisor (GCD) of all numbers between P and Q inclusive is taken (GCD(P, P+1, P+2 ... Q)). As this problem looks a bit easy, it is given that numbers P and Q can be in the range of 10100. You have to return the value of GCD found. Greatest common divisor of 2 numbers A and B is the largest number D that divides both A and B perfectly. Input:
P: String
Q: String
Output: Your function should return a string which contains the digits of the integer which represents the GCD. The returned string should not have any leading zeroes. Constraints:
1 <= P <= Q <= 10^100
Example:
Input:
P: 1
Q: 3

Output:
1

Greatest divisor that divides both 1 and 3 is 1.

Input:
P: 3412
Q: 3412


Output:
3412

As both the numbers are the same, greatest divisor that divides 3412 is 3412.

*/

string Solution::solve(string A, string B) {
    //The logic behind it is GCD of consecutive numbers is always 1, so no need to take gcd of the range, but if numbers are equal return number
    if(A==B)
        return A;
    else
        return "1";

}
