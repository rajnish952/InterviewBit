/*
Chocolate Distribution
Given an array A of N integers where each value represents number of chocolates in a packet. i-th can have A[i] number of chocolates. There are B number students, the task is to distribute chocolate packets following below conditions:
1. Each student gets one packet.
2. The difference between the number of chocolates in packet with maximum chocolates and packet with minimum chocolates given to the students is minimum.
Return the minimum difference (that can be achieved) between maximum and minimum number of chocolates distributed. CONSTRAINTS
0 <= N <= 10^5
1 <= A[i] <= 10^6
0 <= B <= 10^5
SAMPLE INPUT
A : [3, 4, 1, 9, 56, 7, 9, 12]
B : 5
SAMPLE OUTPUT
6
EXPLANATION
Minimum Difference is 6
The set goes like 3,4,7,9,9 and the output 
is 9-3 = 6
*/

// Sort the array and for each window check min, using sliding window

int Solution::solve(vector<int> &A, int B) {
    if(A.size()==0 || B==0)
        return 0;
    if(A.size()==1)
        return A[0];
    sort(A.begin(), A.end());
    int min=INT_MAX;
    int n=A.size();
    for(int i=0;i<=n-B;i++){
        if(A[i+B-1]-A[i]<min)
            min=A[i+B-1]-A[i];
    }
    return min;
}
