/*
Left view of binary tree
Given a binary tree of integers. Return an array of integers representing the left view of the Binary tree. Left view of a Binary Tree is a set of nodes visible when the tree is visited from Left side Constraints
1 <= Number of nodes in binary tree <= 100000
0 <= node values <= 10^9 
For Example
Input 1:
            1
          /   \
         2    3
        / \  / \
       4   5 6  7
      /
     8 
Output 1:
    [1, 2, 4, 8]

Input 2:
            1
           /  \
          2    3
           \
            4
             \
              5
Output 2:
    [1, 2, 4, 5]
*/

// Traverse left most elements and store

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void leftView(TreeNode *A, vector<int> &res)
{
    if (A == NULL)
        return;

    res.emplace_back(A->val);
    leftView(A->left, res);
}
vector<int> Solution::solve(TreeNode *A)
{
    vector<int> res;
    leftView(A, res);
    return res;
}
