class DLLNode {
    public:
    DLLNode *next;
    DLLNode *prev;
    int val;
    int key;
    DLLNode(int key, int val){
        this->key = key;
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
class LRUCache {
public:
    DLLNode *head;
    DLLNode *end;
    int capacity;
    int usedNodes;
    unordered_map<int, DLLNode*> cacheMap;
    LRUCache(int capacity) {
        this->capacity = capacity;
        this->usedNodes = 0;
        head = NULL;
        end = NULL;
    }

    void deleteNodeFromEnd(){
        if(end == NULL) return;
        DLLNode *nextEnd = NULL;
        if(end->next){
            nextEnd = end->next;
            nextEnd->prev = NULL;
        }
        this->cacheMap.erase(end->key);
        if(head == end){
            head = nextEnd;
        }
        delete(end);
        end = nextEnd;
    }

    void addNodeInFront(DLLNode *node){
        //cout
        if(head == NULL){
            head = node;
            end = node;
        }else{
          head->next = node;
          node->prev = head;
          node->next = NULL;
          head = node;
        }
        this->cacheMap[node->key] = node;
    }

    void moveToHead(DLLNode *node){
        if(node == head) return;
        if(node == end){
            end = node->next;
            node->next->prev = NULL;
        }else{
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }
        this->addNodeInFront(node);
    }
    
    int get(int key) {
        if(this->cacheMap.find(key) == this->cacheMap.end()) return -1;
        this->moveToHead(this->cacheMap[key]);
        return this->cacheMap[key]->val;
    }
    
    void put(int key, int value) {
        if(this->cacheMap.find(key) != this->cacheMap.end()) {
            this->cacheMap[key]->val = value;
            this->moveToHead(this->cacheMap[key]);
            return;
        }
        if(this->usedNodes >= this->capacity){
            this->deleteNodeFromEnd();
            this->usedNodes--;
        }
        DLLNode *newNode = new DLLNode(key, value);
        this->addNodeInFront(newNode);
        this->usedNodes++;
    }
    void printLL(){
        DLLNode *temp = end;
        while(temp != NULL){
            cout<<temp->val<<"->";
            temp = temp->next;
        }
        cout<<endl;
    }
};

/*
Missed Edge case
* when only one node is present
* when node to be moved to head has both prev and next
* default value of a pointer is not null
*/