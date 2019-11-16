/*
Merge Two Sorted Lists
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists, and should also be sorted. For example, given following linked lists :
  5 -> 8 -> 20 
  4 -> 11 -> 15
The merged list should be :
4 -> 5 -> 8 -> 11 -> 15 -> 20
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Take two pointer f_h and t_h to track the head and tail of merged list

ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
    
    ListNode *h1=A, *h2=B, *f_h=NULL, *t_h=NULL;
    if(h1->val <= h2->val){ //if first element of L1 <= first element of L2, assign its value to the final nodes and their next would point to null
            f_h=h1;
            t_h=h1;
            h1=h1->next;
            f_h->next=NULL;
            t_h->next=NULL;
        }else{
            f_h=h2;
            t_h=h2;
            h2=h2->next;
            f_h->next=NULL;
            t_h->next=NULL;
        }
    while(h1!=NULL && h2!=NULL){ // while one of the list reches null, assign the values and move next to null
        if(h1->val <= h2->val){
            t_h->next=h1;
            h1=h1->next;
            t_h=t_h->next;
            t_h->next=NULL;
        }else{
            t_h->next=h2;
            h2=h2->next;
            t_h=t_h->next;
            t_h->next=NULL;
        }
    }
    if(h1==NULL && h2!=NULL){ // add remaining elments to the list
        t_h->next=h2;
        return f_h;
    }else if(h1!=NULL && h2==NULL){
        t_h->next=h1;
        return f_h;
    }else{
        return f_h;
    }
    
}
