class Node{
 public:
    int key;
    int value;
    Node* next;
    Node*prev;
    Node(int k,int v){
        key=k;
        value=v;
        next=NULL;
        prev=NULL;
    }
    
};
class LRUCache {
    int cap;
    unordered_map<int,Node*>mpp;
    Node* head=new Node(-1,-1);
    Node* tail=new Node(-1,-1);
public:
void deleteNode(Node * node){
       Node* prevN=node->prev;
        Node* nextN=node->next;
        prevN->next=nextN;
        nextN->prev=prevN;
    }
    void insertNode(Node* node){
        Node * currH=head->next;
        head->next=node;
        node->prev=head;
        node->next=currH;
        currH->prev=node;
    }

    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;     
    }
    
    int get(int key) {
        if(mpp.find(key) != mpp.end())
        {
            Node* node=mpp[key];
            deleteNode(node);
            insertNode(node);

            return node->value;
        }
        else 
            return -1;
        
    }
    
    void put(int key, int value) {
        if(mpp.find(key)!=mpp.end()){
            Node* node=mpp[key];
            node->value=value;
            deleteNode(node);
            insertNode(node);
        }
        else
        {
            if(mpp.size()==cap)
            {
                Node* node=tail->prev;
                mpp.erase(node->key);
                deleteNode(node);
                delete node;
            }
            Node* node=new Node(key,value);
            mpp[key]=node;
            insertNode(node);

        }

        
    }
    
};
