/*
Minimize the absolute difference
Given three sorted arrays A, B and Cof not necessarily same sizes. Calculate the minimum absolute difference between the maximum and minimum number from the triplet a, b, c such that a, b, c belongs arrays A, B, C respectively. i.e. minimize | max(a,b,c) - min(a,b,c) |. Example : Input:
A : [ 1, 4, 5, 8, 10 ]
B : [ 6, 9, 15 ]
C : [ 2, 3, 6, 6 ]
Output:
1
Explanation: We get the minimum difference for a=5, b=6, c=6 as | max(a,b,c) - min(a,b,c) | = |6-5| = 1.
*/

// Logic is to check curr min, now the difference would be min if we select closest value to the smallest max value
// So we decrement value for temp_max

int Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {

    int a=A.size()-1, b=B.size()-1, c=C.size()-1;

    int min_val=INT_MAX;
    while(a!=-1 && b!=-1 && c!=-1){

        int curr_min=std::abs(std::max(A[a], std::max(B[b], C[c])) - std::min(A[a], std::min(B[b], C[c])));
        if(curr_min<min_val)
            min_val=curr_min;

        int temp_max = std::max(A[a], std::max(B[b], C[c])); // To decrease min val, reduce max value of each array
        if(temp_max == A[a])
            a--;
        else if(temp_max == B[b])
            b--;
        else
            c--;
    }

    return min_val;
}
