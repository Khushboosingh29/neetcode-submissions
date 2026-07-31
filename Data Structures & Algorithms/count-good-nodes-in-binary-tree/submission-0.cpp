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

  int  countG(TreeNode* node,int maxs){
    int count=0;
    if(node==NULL)
        return 0;
  if(node->val>=maxs)
    count=1;
  
  else
    count=0;
    maxs=max(node->val,maxs);
    count+=countG(node->left,maxs);
    count+=countG(node->right,maxs);
    return count;
  }
  
public:
    int goodNodes(TreeNode* root) {
        return countG(root,root->val);
        
    }
};
