/*
Min XOR value
Given an array of N integers, find the pair of integers in the array which have minimum XOR value. Report the minimum XOR value. Examples :
Input
0 2 5 7
Output
2 (0 XOR 2)
Input
0 4 7 9
Output
3 (4 XOR 7) Constraints:
2 <= N <= 100 000
0 <= A[i] <= 1 000 000 000
*/

// the idea is the min XOR would be for the numbers which are closes to each other(or set bits are towards LSB), so sort all the numbers and take 
//consecutive XOR to find min

int Solution::findMinXor(vector<int> &A) {
    int min_val=INT_MAX;
    sort(A.begin(), A.end());
    for(int i=1;i<A.size();i++){
        int t=(A[i-1]^A[i]);
        if(t<min_val)
            min_val=t;
    }
    
    return min_val;
}
