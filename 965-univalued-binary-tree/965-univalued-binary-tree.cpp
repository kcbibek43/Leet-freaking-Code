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
    int value;
    bool solve(TreeNode* root){
             if(root==NULL){
            return true;
        }
        if(root->val == value){
            return solve(root->left) && solve(root->right);
        }
        return false;
    }
    bool isUnivalTree(TreeNode* root){
        if(root==NULL){
            return true;
        }
    value = root->val;
    return solve(root);
    }
};