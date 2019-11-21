/*
Remove Duplicates from Sorted List
Given a sorted linked list, delete all duplicates such that each element appear only once. 
For example, Given 1->1->2, return 1->2. Given 1->1->2->3->3, return 1->2->3.
*/

//Traverse link list till curr reaches null, if curr->data is equal to curr->next->data delete curr

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
    ListNode *curr=A, *temp;
    while(curr->next!=NULL){
        if(curr->val == curr->next->val){
            temp=curr->next->next;
            delete(curr->next);
            curr->next=temp;
        }else{
            curr=curr->next;
        }
    }
    return A;
}
