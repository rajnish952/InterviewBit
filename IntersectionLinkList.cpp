/*
Intersection of Linked Lists
Write a program to find the node at which the intersection of two singly linked lists begins. For example, the following two linked lists:
A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗
B:     b1 → b2 → b3
begin to intersect at node c1.
 Notes:
If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.
*/

//Check which list is greater in size, move the pointer of that list by d distance, now both the list pointers are equidistant from the intersection

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::getIntersectionNode(ListNode* A, ListNode* B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    ListNode *p1=A, *p2=B;
    int lenA=0, lenB=0, d=0;
    while(p1!=NULL){
        lenA++;
        p1=p1->next;
    }
    while(p2!=NULL){
        lenB++;
        p2=p2->next;
    }
    
    if(lenA>lenB){
        d=lenA-lenB;
        while(d--){
            A=A->next;
        }
        
    }else{
        d=lenB-lenA;
        while(d--){
            B=B->next;
        }
    }
    
    while(A!=NULL && B!=NULL){
        if(A==B){
            return A;
        }
        A=A->next;
        B=B->next;
    }
    return NULL;
}
