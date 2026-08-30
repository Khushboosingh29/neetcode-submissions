class node{
    node *link[26]={NULL};
    bool flag=false;
public:
    bool containkey(char ch){
        return link[ch-'a']!=NULL;
    }
    void put(char ch,node* n){
        link[ch-'a']=n;
    }
    node* get(char ch){
         return link[ch-'a'];
    }
    void setend(){
        flag=true;
    }
    bool isend()
    {
        return flag;
    }

};

class PrefixTree {
    node* root;
public:
    PrefixTree() {
        root=new node;
        
    }
    
    void insert(string word) {
        node *n=root;
        for(int i=0;i<word.size();i++){
            if(!n->containkey(word[i]))
            {
               n->put(word[i],new node);
            }
          n= n->get(word[i]);
        }

       n->setend();
    }
    
    bool search(string word) {
        
         node *n=root;
        for(int i=0;i<word.size();i++){
            if(!n->containkey(word[i]))
            {
                return false;
            }
          n= n->get(word[i]);
        }
        return n->isend();
    }
    
    bool startsWith(string prefix) {
        node *n=root;
        for(int i=0;i<prefix.size();i++){
            if(!n->containkey(prefix[i]))
            {
                return false;
            }
          n= n->get(prefix[i]);
        }
        return true;
        
    }
};
