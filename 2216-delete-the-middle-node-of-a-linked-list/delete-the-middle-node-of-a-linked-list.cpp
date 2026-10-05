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
    ListNode* deleteMiddle(ListNode* head) {

        if (head == nullptr || head->next == nullptr)
            return nullptr;

        int length = 0;
        ListNode* temp = head;

        while (temp != nullptr) {
            length++;
            temp = temp->next;
        }

        int mid = length / 2;

        temp = head;

        for (int i = 0; i < mid - 1; i++) {
            temp = temp->next;
        }

        ListNode* delNode = temp->next;
        temp->next = temp->next->next;
        delete delNode;

        return head;
    }
};