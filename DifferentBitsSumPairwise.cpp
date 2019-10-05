/*
Different Bits Sum Pairwise
We define f(X, Y) as number of different corresponding bits in binary representation of X and Y. For example, f(2, 7) = 2, since binary representation of 2 and 7 are 010 and 111, respectively. The first and the third bit differ, so f(2, 7) = 2. You are given an array of N positive integers, A1, A2 ,..., AN. Find sum of f(Ai, Aj) for all pairs (i, j) such that 1 ≤ i, j ≤ N. Return the answer modulo 109+7. For example,
A=[1, 3, 5]

We return

f(1, 1) + f(1, 3) + f(1, 5) + 
f(3, 1) + f(3, 3) + f(3, 5) +
f(5, 1) + f(5, 3) + f(5, 5) =

0 + 1 + 1 +
1 + 0 + 2 +
1 + 2 + 0 = 8
*/

// Trick is to find count of zero's and ones's in each col of numbers and for all digits sum up 2*cnt0*cnt1 would be the answer
int Solution::cntBits(vector<int> &A) {
    
    int nb = sizeof(int) * 8;
    int cnt=0;
    for(int i=0;i<nb;i++){
        int cnt0=0, cnt1=0;
        for(int j=0;j<A.size();j++){
            if(A[j] & (1<<i))
                cnt1++;
            else
                cnt0++;
        }
        cnt = (int)(cnt + (2*(cnt0%1000000007  *1l* cnt1%1000000007)) % 1000000007) % 1000000007; // Taking multiplication with 1L converts it into long and then take int value out of it
    }
 return cnt;   
}
