/*
Repeated Subtraction
You are given 2 numbers P and Q. An operation on these 2 numbers is defined as follows: Take the smaller number of the 2 numbers and subtract it from the bigger number. Keep performing this operation till either of the following criterion is met:
Both numbers become equal.
Either of the number becomes 0.
Find the sum of the final values of P and Q. Constraints:
 0 <= P,Q <= 1e9
Input:
Two integers P and Q
Output:
Sum of the final values of P and Q
Example: Input:
P : 5 
Q : 15
Output:
10
*/

int getFinal_driver(int A, int B){
    if(B==0)
        return A+A;
        
    if(A==B)
        return A+B;
    
    return getFinal_driver(B, A%B);
}

int Solution::getFinal(int a, int b) {
    
    if(a==0)
        return b;
    if(b==0)
        return a;
        
    return (a>b) ? getFinal_driver(a,b): getFinal_driver(b,a);
}
