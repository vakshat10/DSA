/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        // If any list is empty, intersection is not possible
        if (headA == NULL || headB == NULL)
            return NULL;

        ListNode* temp1 = headA;
        ListNode* temp2 = headB;

        // Traverse both lists
        while (temp1 != temp2) {

            // When temp1 reaches end, switch to list B
            if (temp1 == NULL)
                temp1 = headB;
            else
                temp1 = temp1->next;

            // When temp2 reaches end, switch to list A
            if (temp2 == NULL)
                temp2 = headA;
            else
                temp2 = temp2->next;
        }

        // Either intersection node or NULL
        return temp1;
    }
};