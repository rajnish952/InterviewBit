/*
Valid Binary Search Tree
Given a binary tree, determine if it is a valid binary search tree (BST). Assume a BST is defined as follows:
The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
Example :
Input : 
   1
  /  \
 2    3

Output : 0 or False


Input : 
  2
 / \
1   3

Output : 1 or True 
Return 0 / 1 ( 0 for false, 1 for true ) for this problem SOLUTION APPROACH : VIDEO : https://www.youtube.com/watch?v=yEwSGhSsT0U Complete solution in the hints.
*/

// inorder traversal of BST should be in asc order

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
    if (A->val != -1)
        res.emplace_back(A->val);
    inorderTraversal(A->right, res);
}
int Solution::isValidBST(TreeNode *A)
{
    vector<int> res;
    inorderTraversal(A, res);
    //for(auto a: res)
    //   cout<<a<<" ";
    for (int i = 0; i < res.size() - 1; i++)
    {
        if (res[i] >= res[i + 1])
            return 0;
    }
    return 1;
}
