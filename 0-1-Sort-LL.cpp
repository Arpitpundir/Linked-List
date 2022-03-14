ListNode* Solution::solve(ListNode* A) {
    ListNode *prev, *curr;
    prev = A, curr = A;
    while(curr){
            if(curr->val == 0 && curr !=A){
                prev->next = curr->next;
                curr->next = A;
                A = curr;
                curr = prev->next;
            }else{
                prev = curr;
                curr = curr->next;
            }
    }
    return A;
}