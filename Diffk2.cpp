/*
Diffk II
Given an array A of integers and another non negative integer k, find if there exists 2 indices i and j such that A[i] - A[j] = k, i != j. Example : Input :
A : [1 5 3]
k : 2
Output :
1
as 3 - 1 = 2
Return 0 / 1 for this problem.
*/

// Check if elem+B or elem-B exists in map or elem+B exists in map

int Solution::diffPossible(const vector<int> &A, int B)
{

    unordered_map<int, int> m;
    if (A.size() < 2)
        return 0;

    for (int i = 0; i < A.size(); i++)
    {
        if (m.find(A[i] + B) != m.end() || m.find(A[i] - B) != m.end())
            return 1;
        m[A[i]] = 1;
    }

    return 0;
}
