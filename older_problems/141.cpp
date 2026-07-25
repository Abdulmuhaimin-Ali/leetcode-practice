class Solution {
public:
    bool hasCycle(ListNode *head, ListNode* meetingPoint) {

       ListNode *slow = head, *fast = head;
       while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) {
            meetingPoint = slow;
            return true;}
        
       } 
       return false;
    }

    ListNode* startOfCycle(ListNode *head){
        ListNode *meetingPoint = nullptr;
        bool hasACycle = hasCycle(head, meetingPoint);

        if(!hasACycle) return NULL;

        ListNode *slow = head;
        ListNode *fast = meetingPoint;

        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};