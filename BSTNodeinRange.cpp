/*
BST nodes in a range
Given a binary search tree of integers. You are given a range [B, C]. Return the count of the number of nodes that lies in this range. Constraints
1 <= Number of nodes in binary tree <= 100000
0 <= B < = C <= 10^9 
For Example
Input 1:
            15
          /    \
        12      20
        / \    /  \
       10  14  16  27
      /
     8

     B = 12
     C = 20
Output 1:
    5

Input 2:
             8
            / \
           6  21
          / \
         1   4

        B = 2
        C = 20
Output 2:
    3
*/

// Do any traversal and check if element in range
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int inRange(TreeNode *A, int B, int C)
{
    if (A == NULL)
        return 0;

    int ans = 0;
    if (A->val >= B && A->val <= C)
        ans++;
    return ans + inRange(A->left, B, C) + inRange(A->right, B, C);
}
int Solution::solve(TreeNode *A, int B, int C)
{

    return inRange(A, B, C);
}
