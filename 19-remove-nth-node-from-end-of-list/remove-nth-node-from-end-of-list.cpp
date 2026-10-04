class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* fast = head;
        ListNode* slow = head;

        // Move fast n steps ahead
        while (n--) {
            fast = fast->next;
        }

        // If head needs to be removed
        if (fast == nullptr)
            return head->next;

        // Move both pointers
        while (fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        // Delete nth node from end
        slow->next = slow->next->next;

        return head;
    }
};