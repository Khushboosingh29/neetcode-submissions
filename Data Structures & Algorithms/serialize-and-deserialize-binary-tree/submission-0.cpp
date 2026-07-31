/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL)
        return "";
        queue<TreeNode*>q;
        q.push(root);
        string res="";
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            if(node==NULL)
            res.append("#,");
            else
            res.append(to_string(node->val)+",");
            if(node!=NULL){
                q.push(node->left);
                q.push(node->right);
            }

        }
        return res;
      
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {

        if(data.size()==0)
            return NULL;
        stringstream s(data);
        string str;
        getline(s,str,',');
        TreeNode* root=new TreeNode(stoi(str));
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){

            TreeNode* node=q.front();
            q.pop();
            getline(s,str,',');
            if(str=="#")
                node->left=NULL;
            else{
                 TreeNode* lnode=new TreeNode(stoi(str));
                 node->left=lnode;
                 q.push(lnode);
                 }
            getline(s,str,',');
            if(str=="#")
                node->right=NULL;
            else{
                 TreeNode* rnode=new TreeNode(stoi(str));
                 node->right=rnode;
                 q.push(rnode);
                 }

        }
        return root;
            
        
    }
};
