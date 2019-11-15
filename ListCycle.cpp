/*
List Cycle
Given a linked list, return the node where the cycle begins. If there is no cycle, return null. Try solving it using constant additional space. Example :
Input : 

                  ______
                 |     |
                 \/    |
        1 -> 2 -> 3 -> 4

Return the node corresponding to node 3. 
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode *Solution::detectCycle(ListNode *A)
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    ListNode *p1 = A, *p2 = A, *head = A;
    int flag = 0;
    int length_loop = 0;

    while (p1 != NULL && p2 != NULL) // loop till slow pounter or fast pointer is not null
    {
        p1 = p1->next;
        if (p2->next == NULL)
        { // if next of fast pointer is null, no loop
            return NULL;
        }
        else
        {
            p2 = p2->next->next; // increment fast pointer by 2
        }

        if (p1 == p2)
        { // Fast pointer equals slow pointer loop found
            //length_loop+=1;
            break;
        }
    }

    if (p1 == NULL || p2 == NULL) // is slow or fast pointer reaches NULL no loop
        return NULL;

    while (head != p1)
    { // Current head would be incremented till length of cycle, i.e till it reaches to slow pointer
        head = head->next;
        p1 = p1->next;
    }

    return head;

    //return NULL;
}
