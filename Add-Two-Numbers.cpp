ListNode* reverse(ListNode* root){
    if(!root) return NULL;

    ListNode *curr = root, *prev = NULL;

    while(curr){
        ListNode *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
ListNode* addRec(int carry, ListNode *n1, ListNode *n2){
    if(!n1 && !n2 && !carry){
        return NULL;
    }
    if(!n1 && !n2){
        ListNode *curr = new ListNode(carry);
        curr->next = NULL;
        return curr;
    }
    int tot = 0;
    ListNode *next1, *next2;
    if(!n1 && n2){
        tot = n2->val+carry;
        next2 = n2->next;
    }
    else if(n1 && !n2){
        tot = n1->val+carry;
        next1 = n1->next;
    }else{
        tot = n1->val+n2->val+carry;
        next1 = n1->next;
        next2 = n2->next;
    }

    ListNode *curr = new ListNode(tot%10);
    curr->next = addRec(tot/10, next1, next2);
    return curr;
}
ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {
    return addRec(0,A,B);
}