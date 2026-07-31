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
void traversal(TreeNode* root,vector<int> &ans){
    if(root==NULL)
        return;

    traversal(root->left,ans);
    ans.push_back(root->val);
    traversal(root->right,ans);
}
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int>res;
        traversal(root,res);
        for(int i=0;i<res.size();i++){
            if(i==k-1)
                return res[i];

        }
       return -1; 
    }
};
