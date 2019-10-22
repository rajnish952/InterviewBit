/*
Counting Triangles
You are given an array of N non-negative integers, A0, A1 ,..., AN-1. Considering each array element Ai as the edge length of some line segment, count the number of triangles which you can form using these array values. Notes:
You can use any value only once while forming each triangle. Order of choosing the edge lengths doesn't matter. Any triangle formed should have a positive area.
Return answer modulo 109 + 7.
For example,
A = [1, 1, 1, 2, 2]

Return: 4
*/

// Use two pointer to track what range could form valid triangles
int Solution::nTriang(vector<int> &A)
{
    int n = A.size();
    int num = pow(10, 9) + 7;
    sort(A.begin(), A.end());
    int count = 0;
    for (int i = n - 1; i >= 1; i--)
    { // Loop through all elements
        int l = 0, r = i - 1;
        while (l < r)
        {   // while l < r && sum of A[l] + A[r] > A[i] that means it could form a valid triangle
            //so all the elemnts between l+1 and r-1(inclusive) could also form valid triabgle, so count+=(r-l)
            if (A[l] + A[r] > A[i])
            {
                count = (count + (r - l) % num) % num; // take mod of subtraction and the mod of sum as well
                r--;
            }
            else
                l++;
        }
    }
    return count;
}
