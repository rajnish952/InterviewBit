/*
Path Sum
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum. Example : Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22. Return 0 / 1 ( 0 for false, 1 for true ) for this problem
*/

// Traverse the tree, and subtract each node val from given value, now if we reach leaf node and given val becomes zero return true else return false

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::hasPathSum(TreeNode *A, int B)
{
    if (A == NULL) // base case
        return 0;

    B -= A->val;                             // reduce B val
    if (A->left == NULL && A->right == NULL) // leaf node condition
    {
        if (B == 0)
            return 1;
    }

    return hasPathSum(A->left, B) || hasPathSum(A->right, B); // if any subtree has a path return true
}
