/*
Sum Root to Leaf Numbers
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number. An example is the root-to-leaf path 1->2->3 which represents the number 123. Find the total sum of all root-to-leaf numbers % 1003. Example :
    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12. The root-to-leaf path 1->3 represents the number 13. Return the sum = (12 + 13) % 1003 = 25 % 1003 = 25.
*/

// Traverse the tree in preorder and form the sum, val*10+root->val

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int treeSum(TreeNode *A, int val)
{
    if (A == NULL) // base condition
        return 0;
    val = val * 10 + A->val; // calculate val
    val %= 1003;
    if (A->left == NULL && A->right == NULL) // if leaf node encountered return sum
        return val;

    return treeSum(A->left, val) + treeSum(A->right, val); // return sum of left and right subtree
}

int Solution::sumNumbers(TreeNode *A)
{

    int val = 0;
    return treeSum(A, val) % 1003;
}
