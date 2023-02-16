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

    void deleteNode(DLLNode *node){
        //cout<<"end 1"<<end->val<<endl;

        if(end->next){
            end = end->next;
            end->prev = NULL;
        }else{
            end = NULL;
        }
        //cout<<"end 2"<<end->val<<endl;
        this->cacheMap.erase(node->key);
        delete node;
        this->usedNodes--;
    }

    void addNode(DLLNode *node, int key){
        //cout<<"add "<<key<<endl;
        if(!head) {
            head = node;
            end = node;
        }else{
            head->next = node;
            node->prev = head;
            head = node;
        }
        this->usedNodes++;
        this->cacheMap[key] = node;
                //cout<<"add "<<head->val<<endl;

        return;
    }

    void moveToHead(DLLNode *node){
        if(node->prev){
            node->prev->next = node->next;
        }
        if(node->next){
            node->next->prev = node->prev;
            if(node == end){
                end = node->next;
            }
        }
        if(head != node){
            node->prev = head;
            head->next = node;
            node->next = NULL;
            head = node;
        }
    }
    
    int get(int key) {
        // check in map
        //cout<<this->cacheMap[key]->val<<" cacheMap"<<endl;
       // cout<<"get "<<key<<endl;
        if(this->cacheMap.count(key) == 0) return -1;
        this->moveToHead(this->cacheMap[key]);
       // this->printLL();
        return this->cacheMap[key]->val;
    }
    
    void put(int key, int value) {
        if(this->usedNodes >= this->capacity){
            this->deleteNode(end);
        }
        DLLNode *newNode = new DLLNode(key, value);
        this->addNode(newNode, key);
        //this->printLL();
        //cout<<"put "<<head->val<<endl;
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
