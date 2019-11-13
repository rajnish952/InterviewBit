/*
Remove Nth Node from List End
Given a linked list, remove the nth node from the end of list and return its head. For example, Given linked list: 1->2->3->4->5, and n = 2. 
After removing the second node from the end, the linked list becomes 1->2->3->5.
 Note:
If n is greater than the size of the list, remove the first node of the list.
Try doing it using constant additional space.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 // Use two pointers increment one by B and then increment both pointer till p2->next!=NULL so p1 would point to the element to be deleted
ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {
    
    ListNode *p1=A, *p2=A;
    
    if(!A->next)
        return NULL;
        
    while(B--){ 
        p2=p2->next; 
        if(p2==NULL){ // if B is greater than N it would reach NULL, so return head->next
            return p1->next;
        }
    }
    
    while(p2->next!=NULL){
        p2=p2->next;
        p1=p1->next;
    }
    p1->next=p1->next->next;
    return A;
    
}
