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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
                vector<vector<int>> a;
        if(root==NULL){
            return a;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int len = q.size();
            vector<int> row;
            for(int i=0;i<len;i++){
             TreeNode* n = q.front();
                q.pop();
                row.push_back(n->val);
                if(n->left!=NULL){
                    q.push(n->left);
                }
                if(n->right!=NULL){
                    q.push(n->right);
                }
            }
            a.push_back(row);
    }
        reverse(a.begin(),a.end());
        return a;
    }
};