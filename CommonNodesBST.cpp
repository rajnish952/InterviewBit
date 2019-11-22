/*
Common Nodes in Two Binary Search Trees
Given two BSTs, return the sum of all common nodes in both. In case there is no common node, return 0 NOTE
1. Your code will run on multiple test cases, please come up with an optimised solution.
2. Try to do it one pass through the trees.
INPUT FORMAT
A : Root of Tree A
B : Root of Tree B
EXAMPLE INPUT
Tree A:
    5
   / \
  2   8
   \   \
    3   15
        /
        7

Tree B:
    7
   / \
  1  10
   \   \
    2  15
       /
      8
EXAMPLE OUTPUT
38
EXAMPLE EXPLANATION
Common Nodes are : 2, 7, 8, 15
So answer is 2 + 7 + 8 + 15 = 32
*/

// Traverse one BST store it in unordered_set, now for all elements of second BST if found in set add it to sum

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
unordered_set<int> us;

void preorderTraversal(TreeNode *A)
{
    if (A == NULL)
        return;

    us.insert(A->val);
    preorderTraversal(A->left);
    preorderTraversal(A->right);
}

int returnSum(TreeNode *B)
{
    if (B == NULL)
        return 0;

    int sum = 0;
    int left = returnSum(B->left);
    if (us.find(B->val) != us.end())
    {
        sum += B->val;
    }
    int right = returnSum(B->right);
    return sum + left + right;
}

int Solution::solve(TreeNode *A, TreeNode *B)
{

    us.clear();
    preorderTraversal(A);
    return returnSum(B);
}
