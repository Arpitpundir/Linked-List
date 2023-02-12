class Solution {
public:
    void reorderList(ListNode* head) {
        if(head->next == NULL || head->next->next == NULL) return;

        ListNode *fast = head, *slow = head, *end = NULL;
        while(fast == NULL){
            if(fast->next != NULL && fast->next->next == NULL){
                end = fast->next;
                fast = fast->next->next;
            }else if(fast->next == NULL){
                end = fast;
                fast = fast->next;
                break;
            }else{
                fast = fast->next->next;
            }
            slow = slow->next;
        }

        ListNode *mid = slow, *temp = mid->next, *prev = mid;

        while(temp!=NULL){
            ListNode *nxt = temp->next;
            temp->next = prev;
            prev = temp;
            temp = nxt;
        }

        ListNode *currLeft = head, *currRight = end, *nxtLeft = NULL, *nxtRight = NULL;

        while(true){
            nxtLeft = currLeft->next;
            nxtRight = currRight->next;
            currLeft->next = currRight;
            currRight->next = nxtLeft;
            currLeft = nxtLeft, currRight = nxtRight;
            if(currLeft == currRight || currLeft->next == currRight){
                currRight->next = NULL;
                break;
            }
        }
    }
};