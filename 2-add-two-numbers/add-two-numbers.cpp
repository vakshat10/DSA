/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum = 0;
        int carry = 0;

        // Dummy node to build the answer list
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;

        // Continue until both lists are completely processed
        while (l1 != nullptr || l2 != nullptr) {

            // Take value from list, or 0 if list has ended
            int val1 = (l1 != nullptr) ? l1->val : 0;
            int val2 = (l2 != nullptr) ? l2->val : 0;

            // Add both values along with carry
            sum = val1 + val2 + carry;

            // Store the current digit and carry the remaining value
            int digit = sum % 10;
            carry = sum / 10;

            // Create a node for the current digit
            ListNode* newNode = new ListNode(digit);

            // Attach the new node to the answer list
            temp->next = newNode;
            temp = temp->next;

            // Move l1 if it still exists
            if (l1 != nullptr)
                l1 = l1->next;

            // Move l2 if it still exists
            if (l2 != nullptr)
                l2 = l2->next;
        }

        // Add the remaining carry, if any
        if (carry != 0) {
            ListNode* newNode = new ListNode(carry);
            temp->next = newNode;
        }

        // Skip the dummy node and return the actual answer
        ListNode* ans = dummy->next;
        delete dummy;
        return ans;
        
    }
};