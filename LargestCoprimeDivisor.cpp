/*
Largest Coprime Divisor
You are given two positive numbers A and B. You need to find the maximum valued integer X such that:
X divides A i.e. A % X = 0
X and B are co-prime i.e. gcd(X, B) = 1
For example,
A = 30
B = 12
We return
X = 5
*/

//The idea is to keep dividing A by gcd(A,B) i.e. remove all common factors of A, B from A, untill gcd(A,B) = 1

int Solution::cpFact(int A, int B) {
    
    while(__gcd(A,B)!=1){
        A/=__gcd(A,B);
    }
    return A;
    
}