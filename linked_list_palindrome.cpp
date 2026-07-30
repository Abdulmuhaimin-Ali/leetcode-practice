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
        ListNode* curr = node;
        ListNode* prev = nullptr;
        while(curr){
            ListNode* next_temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next_temp;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;

        ListNode* slow = head;
        ListNode* fast = head;

        // find middle
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* second_half = reverseLinkedList(slow);

        ListNode* first_half = head;
        while(second_half && first_half){
            if(second_half->val != first_half->val){
                return false;
                break;
            }
            first_half = first_half->next;
            second_half = second_half->next;
        }
        return true;
    }
};