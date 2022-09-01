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
    void find(TreeNode* root,vector<int> &a){
        if(root==NULL){
           return;
        }
        find(root->left,a);
        a.push_back(root->val);
        find(root->right,a);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> a;
        find(root,a);
        return a[k-1];
    }
};