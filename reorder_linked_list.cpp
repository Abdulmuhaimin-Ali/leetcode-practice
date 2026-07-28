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

    ListNode* reverseLinkedList(ListNode* node){
        ListNode* curr = node->next;
        node->next = nullptr;
        ListNode* prev = nullptr;
        
        while(curr){
            ListNode* next_temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next_temp;
        }
        curr = prev;
        return curr;
    }

    void reorderList(ListNode* head) {
        if (!head || !head->next) return;
        
       // find middle
       ListNode* slow = head;
       ListNode* fast = head;
       while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
       }

       // reverse second half
       ListNode* second = reverseLinkedList(slow);

       // merge two halves
       ListNode* first = head;
       while(second){
        ListNode* tmp1 = first->next;
        ListNode* tmp2 = second->next;

        first->next = second;
        second->next = tmp1;
        first = tmp1;
        second = tmp2;
       }
    }
};