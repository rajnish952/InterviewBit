/*
Implement Power Function
Implement pow(x, n) % d. In other words, given x, n and d, find (xn % d) Note that remainders on division cannot be negative. In other words, make sure the answer you return is non negative.
Input : x = 2, n = 3, d = 3
Output : 2

2^3 % 3 = 8 % 3 = 2.
*/

// Recurssive call to find a^(b/2)

int Solution::pow(int x, int n, int d) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(n==1)
    {
        return x>0?abs(x%d):d-abs(x%d);
    }
    if(n==0)
        return abs(1%d);
        
    long long int t=pow(x,n/2,d);
    if(n%2==0){
        return abs((t%d)*(t%d))%d;
    }else{
        return abs((x%d*t%d*t%d))%d;
    }
}
