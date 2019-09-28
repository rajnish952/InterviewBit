/*
Find if two rectangles overlap
Given eight integers A, B, C, D, E, F, G and H which represent two rectangles in a 2D plane. For the first rectangle it's bottom left corner is (A, B) and top right corner is (C, D) and for the second rectangle it's bottom left corner is (E, F) and top right corner is (G, H). Find and return whether the two rectangles overlap or not. 
Input Format
The eight arguments given are the integers A, B, C, D, E, F, G and H.
Output Format
Return 1 if the two rectangles overlap else return 0.
Constraints
-10000 <= A < C <= 10000
-10000 <= B < D <= 10000
-10000 <= E < G <= 10000
-10000 <= F < H <= 10000
For Example
Input 1:
    A = 0   B = 0
    C = 4   D = 4
    E = 2   F = 2
    G = 6   H = 6
Output 1:
    1

Input 2:
    A = 0   B = 0
    C = 4   D = 4
    E = 2   F = 2
    G = 3   H = 3
Output 2:
    1
*/

// Logic is to check if one rectange is in the left of other rectangle or above it, then they don't overlap
int Solution::solve(int A, int B, int C, int D, int E, int F, int G, int H) {
    
    if(B>=H || F>=D)
    return 0;
    if(A>=G || E>=C)
    return 0;
    
    return 1;
    
}
