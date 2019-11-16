/*
Palindrome List
Given a singly linked list, determine if its a palindrome. Return 1 or 0 denoting if its a palindrome or not, respectively. Notes:
Expected solution is linear in time and constant in space.
For example,
List 1-->2-->1 is a palindrome.
List 1-->2-->3 is not a palindrome.
*/

// Push everything to stack and compare all elements or reverse the list and compare
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
    ListNode *head=A;
    while(head!=NULL){
        s.push(head->val);
        head=head->next;
    }
    //ListNode *temp=A;
    while(A!=NULL){
        if(A->val != s.top()){
            return 0;
        }
        A=A->next;
        s.pop();
        
    }
    return 1;
}
