class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* head1=head,*head2;
        if(head1==NULL)
            return NULL;
        
        unordered_map<Node*,int> nodeToInd;
        vector<Node*> indToNewNode;
        int count=0;
        
        head2=new Node(head1->val);
        Node* prev=head2;
        nodeToInd[head1]=count++;
        indToNewNode.push_back(head2);
        head1=head1->next;
        /*
        * create new list with next pointers
        * push new node in vector
        * store index of new node corresponding to old node in map
        */
        while(head1!=NULL){
            Node* curr=new Node(head1->val);
            prev->next=curr;
            prev=curr;
            nodeToInd[head1]=count++;
            indToNewNode.push_back(curr);
            head1=head1->next;
        }
        prev->next=NULL;
        
        head1=head;
        Node* curr=head2;
        /*
        * set random pointers with help of map and vector
        */
        while(head1!=NULL){
            if(head1->random==NULL){
                curr->random=NULL;
            }else{
                int randNodeInd=nodeToInd[head1->random];
                curr->random=indToNewNode[randNodeInd];
            }
            head1=head1->next;
            curr=curr->next;
        }
        return head2;
    }
};