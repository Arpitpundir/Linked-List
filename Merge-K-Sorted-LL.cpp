/*
* Time Complexity: O(nk) where n is the number of nodes in the final list and k is the number of lists
* Space Complexity: O(n) where n is the number of nodes in the final list
*/
class Solution {
public:
void printLL(ListNode *node){
    while(node != NULL){
        cout<<node->val<<" ";
        node = node->next;
    }
    cout<<endl;
}
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        ListNode *ansHead = NULL, *ansEnd = NULL;
        if(!n) return ansHead;
        int completedListCount = 0;

        /*
        * We will keep on iterating over the lists and find the node with the minimum value
        * create a new node and add it to the final list
        * update the list from which the node was taken
        * if the list is empty, increment the completedListCount
        */
        while(completedListCount < n){
            int nextNodeIndex = -1, nextNodeValue = INT_MAX;
            for(int i=0;i<n;i++){
                if(lists[i] && lists[i]->val < nextNodeValue){
                    nextNodeIndex = i;
                    nextNodeValue = lists[i]->val;
                }
            }
            if(nextNodeIndex == -1) break;
            ListNode *newNode = new ListNode(nextNodeValue);
            if(ansHead == NULL){
                ansHead = newNode;
                ansEnd = newNode;
            }else{
                ansEnd->next = newNode;
                ansEnd = ansEnd->next;
            }
            lists[nextNodeIndex] = lists[nextNodeIndex]->next;
            if(lists[nextNodeIndex] == NULL) completedListCount++;
        }
        return ansHead;
    }
};