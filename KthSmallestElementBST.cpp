/*
Kth Smallest Element In Tree
Given a binary search tree, write a function to find the kth smallest element in the tree. Example :
Input : 
  2
 / \
1   3

and k = 2

Return : 2

As 2 is the second smallest element in the tree.
 NOTE : You may assume 1 <= k <= Total number of nodes in BST 
*/

// Do the Inorder Traversal of BST it would be sorted, return B-1 element

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void inorderTraversal(TreeNode *A, vector<int> &res)
{

    if (A == NULL)
        return;

    inorderTraversal(A->left, res);
    res.emplace_back(A->val);
    inorderTraversal(A->right, res);
}
int Solution::kthsmallest(TreeNode *A, int B)
{
    vector<int> res;
    inorderTraversal(A, res);
    return res[B - 1];
}
