class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL) return NULL;
        int cnt=0;
        /*
        * count number of nodes present if number of nodes is less than k, return the head and do nothing
        * else reverse the first k nodes and recursively call the function on the remaining nodes
        */
        ListNode* root=head;
        while(cnt<k&&root!=NULL){
            cnt++;
            root=root->next;
        }
        if(cnt<k) return head;

        ListNode* prev=NULL;
        cnt=0,root=head;
        while(cnt<k){
            ListNode* temp=root->next;
            root->next=prev;
            prev=root;
            root=temp;
            cnt++;
        }
        if(root!=NULL)
            head->next=reverseKGroup(root,k);
        return prev;
    }
};
