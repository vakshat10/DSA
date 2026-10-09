class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        // Handle empty lists
        if(list1 == nullptr) return list2;
        if(list2 == nullptr) return list1;

        ListNode* temp1 = list1;
        ListNode* temp2 = list2;

        ListNode* head = nullptr;
        ListNode* tail = nullptr;

        // Choose the smaller node as the head
        if(temp1->val <= temp2->val) {
            head = temp1;
            tail = head;
            temp1 = temp1->next;
        }
        else {
            head = temp2;
            tail = head;
            temp2 = temp2->next;
        }

        // Compare nodes and attach the smaller one
        while(temp1 != nullptr && temp2 != nullptr) {
            if(temp1->val <= temp2->val) {
                tail->next = temp1;
                temp1 = temp1->next;
            }
            else {
                tail->next = temp2;
                temp2 = temp2->next;
            }

            tail = tail->next;
        }

        // Attach the remaining nodes
        if(temp1 != nullptr)
            tail->next = temp1;
        else
            tail->next = temp2;

        return head;
    }
};