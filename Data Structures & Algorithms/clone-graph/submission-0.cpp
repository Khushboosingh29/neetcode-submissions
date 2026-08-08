/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
unordered_map<Node*,Node*>mpp;
void dfs(Node* node,Node* clone){

    for(Node* n:node->neighbors){
        if(mpp.find(n)==mpp.end()){
            Node* clone_n=new Node(n->val);
            mpp[n]=clone_n;
            clone->neighbors.push_back(clone_n);
            dfs(n,clone_n);

        }
        else
             clone->neighbors.push_back(mpp[n]);
    }
}
    Node* cloneGraph(Node* node) {
                if(node==NULL)
        return NULL;

        Node* clone =new Node(node->val);
        mpp[node] = clone;
        dfs(node,clone);
        return clone;
        
        
    }
};
