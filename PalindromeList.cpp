/*
Palindrome List
Given a singly linked list, determine if its a palindrome. Return 1 or 0 denoting if its a palindrome or not, respectively. Notes:
Expected solution is linear in time and constant in space.
For example,
List 1-->2-->1 is a palindrome.
List 1-->2-->3 is not a palindrome.
*/

// Push everything to a stack, check val in LL and stack if equal its palindrome else not

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int Solution::lPalin(ListNode* A) {
    stack<int> s;
    ListNode *ref = A;
    while(ref != NULL){
        s.push(ref->val);
        ref=ref->next;
    }
    while(!s.empty() && A != NULL){
        if(s.top() != A->val)
            return 0;
        s.pop();
        A=A->next;
    }
    return 1;
}
