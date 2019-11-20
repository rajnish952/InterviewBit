/*
Inorder Traversal
Given a binary tree, return the inorder traversal of its nodes' values. Example : Given binary tree
   1
    \
     2
    /
   3
return [1,3,2]. Using recursion is not allowed.
*/

//Recursive
// Inorder process left subtree -> process root -> process right subtree

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void inorderHelper(TreeNode *A, vector<int> &res)
{
    if (A == NULL)
        return;
    inorderHelper(A->left, res);
    res.emplace_back(A->val);
    inorderHelper(A->right, res);
}

vector<int> Solution::inorderTraversal(TreeNode *A)
{
    vector<int> res;
    inorderHelper(A, res);
    return res;
}

// Iterative approach

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::inorderTraversal(TreeNode *A)
{

    vector<int> res;
    stack<TreeNode *> s;
    TreeNode *curr = A;

    while (curr != NULL || !s.empty())
    {

        while (curr != NULL)
        {
            s.push(curr);
            curr = curr->left;
        }

        curr = s.top();
        res.emplace_back(curr->val);
        s.pop();
        curr = curr->right;
    }

    return res;
}
