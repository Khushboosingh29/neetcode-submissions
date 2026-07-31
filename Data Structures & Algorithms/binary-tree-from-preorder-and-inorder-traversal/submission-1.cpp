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

class Solution {
public:
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>imap;
        for(int i=0;i<inorder.size();i++){
            imap[inorder[i]]=i;
        }
       return  build(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,imap);
    }

TreeNode* build(vector<int>& preorder,int ps,int pe,vector<int>& inorder,int is,int ie,unordered_map<int,int> &imap){
    if(ps>pe || is>ie){
        return NULL;
    }
    TreeNode* root=new TreeNode(preorder[ps]);
    int inroot=imap[root->val];
    int numsl=inroot-is;

    root->left=build(preorder,ps+1,ps+numsl,inorder,is,inroot-1,imap);
    root->right=build(preorder,ps+numsl+1,pe,inorder,inroot+1,ie,imap);
    return root;
 }
};
