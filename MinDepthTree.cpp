/*
Min Depth of Binary Tree
Given a binary tree, find its minimum depth. The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
 NOTE : The path has to end on a leaf node. 
Example :
         1
        /
       2
min depth = 2.
*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int traverse(TreeNode *root)
{
    if (root == NULL) // root is NULL return 0
        return 0;

    if (!root->left && !root->right) // only root exist return 1
        return 1;

    if (!root->left) // if left subtree doesnt exist, return 1+size of right subtree
        return 1 + traverse(root->right);

    if (!root->right) // if right subtree doesnt exist, return 1+size of left subtree
        return 1 + traverse(root->left);

    return min(traverse(root->left), traverse(root->right)) + 1; // return min of left and right subtree +1
}
int Solution::minDepth(TreeNode *A)
{

    return traverse(A);
}
