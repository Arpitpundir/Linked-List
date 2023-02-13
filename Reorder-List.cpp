class Solution {
public:
    void reorderList(ListNode* head) {
        if(head->next == NULL || head->next->next == NULL) return;

        ListNode *fast = head, *slow = head, *end = NULL;
        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode *mid = slow, *temp = mid->next, *prev = mid;
        mid->next = NULL;
        while(temp!=NULL){
            ListNode *nxt = temp->next;
            temp->next = prev;
            prev = temp;
            temp = nxt;
        }

        ListNode *currLeft = head, *currRight = prev, *nxtLeft = NULL, *nxtRight = NULL;

        while(currLeft != mid && currRight != mid){
            nxtLeft = currLeft->next;
            nxtRight = currRight->next;
            currLeft->next = currRight;
            currRight->next = nxtLeft;
            currLeft = nxtLeft, currRight = nxtRight;
        }
    }
};