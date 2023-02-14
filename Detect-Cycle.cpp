class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow=head, *fast=head;
        /*
        * If there is a cycle, fast and slow will meet at some point
        * we can prove this by considering the following cases:
        * when slow enters in loop smaller side gap between fast and slow is g
        * everytime when fast and slow moves this gap reduces by one and eventually they will meet
        */
        while(fast){
            if(!fast->next||!fast->next->next)
                return false;
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow)
                return true;
        }
        return false;
    }
};