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
    ListNode* rotateRight(ListNode* head, int k) {

        if(head == nullptr || head->next == nullptr){
            return head;
        }

        ListNode* temp = head;
        ListNode* last = nullptr;
        int length = 0;
        ListNode* prev = nullptr;


        while(temp!= nullptr){
            last = temp;
            temp = temp->next;
            length++;
        }

        k = k%length;
        if(k==0){
            return head;
        }

        temp = head;

        for(int i = 0;i<length-k;i++){
            prev = temp;
            temp = temp->next;
        }

        

        prev->next = nullptr;
        last->next = head;
        head = temp;

        return head;




        
    }
};