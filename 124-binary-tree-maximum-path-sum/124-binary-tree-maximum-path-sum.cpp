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
    int mx(TreeNode* root,int &a){
        if(root==NULL){
            return 0;
        }
        int left=mx(root->left,a);
        int right=mx(root->right,a);
        int nodemax=max(max(root->val+left,root->val+right),max(root->val+left+right,root->val));
        a=max(a,nodemax);
        int sig = max(root->val,max(root->val+left,root->val+right));
        return sig;
    }
    int maxPathSum(TreeNode* root) {
        int a=INT_MIN;
        mx(root,a);
        return a;
    }
};