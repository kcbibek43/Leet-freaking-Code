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
 void find(TreeNode* root, vector<int> &b,int &mn){
        if(root==NULL){
         return;
        }
     b.push_back(root->val);
     mn = min(mn,root->val);
     find(root->left,b,mn);
     find(root->right,b,mn);
    }
    int findSecondMinimumValue(TreeNode* root) {
        vector<int> b;
        int m = INT_MAX;
        find(root,b,m);
        sort(b.begin(),b.end());
        for(int i = 0;i<b.size();i++){
            if(b[i]>m){
                return b[i];
            }
        }
        return -1;
    }
};