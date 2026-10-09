class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        // Handle empty list or single node
        if(head == nullptr || head->next == nullptr){
            return head;
        }

        ListNode* temp = head;
        ListNode* last = nullptr;
        int length = 0;
        ListNode* prev = nullptr;

        // Calculate length and find the last node
        while(temp != nullptr){
            last = temp;
            temp = temp->next;
            length++;
        }

        // Remove unnecessary rotations
        k = k % length;

        // If no rotation is needed
        if(k == 0){
            return head;
        }

        temp = head;

        // Find the new tail (prev) and new head (temp)
        for(int i = 0; i < length-k; i++){
            prev = temp;
            temp = temp->next;
        }

        // Break the list at the new tail
        prev->next = nullptr;

        // Connect the original last node to the original head
        last->next = head;

        // Update head to the new head
        head = temp;

        return head;
    }
};