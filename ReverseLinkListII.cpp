/*
Reverse Link List II
Reverse a linked list from position m to n. Do it in-place and in one-pass. For example: Given 1->2->3->4->5->NULL, m = 2 and n = 4, return 1->4->3->2->5->NULL.
 Note: Given m, n satisfy the following condition: 1 ≤ m ≤ n ≤ length of list. 
 Note 2: Usually the version often seen in the interviews is reversing the whole linked list which is obviously an easier version of this question. 
 */

 /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseBetween(ListNode* A, int B, int C) {
    ListNode *curr=A, *prev=NULL, *next=NULL;
    ListNode *dummy = new ListNode(0), *pre = dummy, *cur;
       dummy -> next = A;
       for (int i = 0; i < B - 1; i++) {
           pre = pre -> next;
       }
       cur = pre -> next;
       for (int i = 0; i < C - B; i++) {
           ListNode* temp = pre -> next;
           pre -> next = cur -> next;
           cur -> next = cur -> next -> next;
           pre -> next -> next = temp;
       }
       return dummy -> next;
}
