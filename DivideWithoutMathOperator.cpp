/*
Divide Integers
Divide two integers without using multiplication, division and mod operator. Return the floor of the result of the division. Example:
5 / 2 = 2
Also, consider if there can be overflow cases. For overflow case, return INT_MAX.
*/

int Solution::divide(int A, int B) {

    long long dividend = (long long)A;
    long long divisor = (long long)B;

    long long sign = (dividend < 0) ^ (divisor < 0) ? -1 : 1;
    dividend = abs(dividend);
    divisor = abs(divisor);
    if (A <= INT_MIN && B == -1) {
            return INT_MAX;
        }

    if (dividend == 0) {
        return 0;
    }

    if (divisor == 1) {
        return int(sign * dividend);
    }

    return int(sign * exp(log(dividend) - log(divisor)) );
}
