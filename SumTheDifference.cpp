/*
Sum the Difference
Given an Array of numbers You have to find all possible non-empty subsets of the array of numbers and then, for each subset, find the difference between the largest and smallest numbers in that subset Then add up all the differences to get the number. As the number may be large, output the number modulo 1e9 + 7 (1000000007).
Example:

A = [1, 2]

All subsets
[1]    largest-smallest = 1 - 1 = 0
[2]    largest-smallest = 2 - 2 = 0
[1 2]  largest-smallest = 2 - 1 = 1

Sum of the differences = 0 + 0 + 1 = 1

So resultant number is 1
Constraints:
1 ≤ N ≤ 10000
*/

// For all subset including a1 as lowest value will be a1*2^(n-1) similarly equation would be sum_of_lowest=(a1*2^(n-1)+ a2*2^(n-2)+...an)
// sum_of_highest=(a1+ a2*2+...an*(2^(n-1))

int Solution::solve(vector<int> &A)
{

    int MOD = 1000000007;
    sort(A.begin(), A.end());
    int n = A.size();

    long long int min_sum = 0, max_sum = 0;
    for (int i = 0; i < n; i++)
    {
        max_sum = 2 * max_sum + A[n - 1 - i];
        max_sum %= MOD;
        min_sum = 2 * min_sum + A[i];
        min_sum %= MOD;
    }

    return (max_sum - min_sum + MOD) % MOD;
}
