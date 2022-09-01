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
    void findcount(TreeNode* root,int &count,int rt){
        if(root==NULL){
            return;
        }
        if(root->val >= rt){
            rt = max(root->val,rt);
            count++;
        }
     findcount(root->left,count,rt);
        findcount(root->right,count,rt);
    }
    int goodNodes(TreeNode* root) {
        int count = 0;
        int rt = root->val;
        findcount(root,count,rt);
        return count;
    }
};