/*
Postorder Traversal
Given a binary tree, return the postorder traversal of its nodes' values. Example : Given binary tree
   1
    \
     2
    /
   3
return [3,2,1]. Using recursion is not allowed.
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

void postorderHelper(TreeNode *A, vector<int> &res)
{

    if (A == NULL)
        return;
    postorderHelper(A->left, res);
    postorderHelper(A->right, res);
    res.emplace_back(A->val);
}

vector<int> Solution::postorderTraversal(TreeNode *A)
{

    vector<int> res;
    postorderHelper(A, res);
    return res;
}
