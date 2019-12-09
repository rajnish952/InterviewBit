/*
Connect ropes with minimum length
Given an array of integers A representing the length of ropes. You need to connect these ropes into one rope. The cost of connecting two ropes is equal to the sum of their lengths. You need to connect the ropes with minimum cost. Find and return the minimum cost to connect these ropes into one rope. 
Input Format
The only argument given is the integer array A.
Output Format
Return the minimum cost to connect these ropes into one rope.
Constraints
1 <= length of the array <= 100000
1 <= A[i] <= 10^3
For Example
Input 1:
    A = [1, 2, 3, 4, 5]
Output 1:
    33
Explanation 1:
    1 + 2 = 3
    3 + 3 = 6
    4 + 5 = 9
    6 + 9 = 15

    3 + 6 + 9 + 15 = 33

Input 2:
    A = [5, 17, 100, 11]
Output 2:
    182
Explanation 2:
    5 + 11 = 16
    16 + 17 = 33
    33 + 100 = 133

    16 + 33 + 133 = 182
*/

// Create min heap, take top two elements, push the sum back and keep track of overall sum

int Solution::solve(vector<int> &A)
{

    priority_queue<int, vector<int>, greater<int>> pq; // Create min heap, using priority queues
    for (auto a : A)
        pq.push(a);

    int sum = 0;

    while (pq.size() > 1)
    { // while queue size greater than 1
        int x = pq.top();
        pq.pop();
        int y = pq.top();
        pq.pop();
        sum += (x + y);
        pq.push(x + y);
    }

    //sum+=pq.top();
    return sum;
}
