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
    vector<double> averageOfLevels(TreeNode* root) {
        // vector<TreeNode*> n1;
        // vector<TreeNode*> n2;
      vector<double> ans;
        if(root==NULL){
            return ans;
        }
        queue<TreeNode*> n1;
        n1.push(root);
        while(!n1.empty()){
            int len = n1.size();
            double sum = 0;
            for(int i = 0;i<len;i++){
            TreeNode* n = n1.front();
                n1.pop();
                sum+=n->val;
                if(n->left!=NULL){
                 n1.push(n->left);
                }
                   if(n->right!=NULL){
                       n1.push(n->right);
                   }
            }
              ans.push_back(sum/len);     
        }
                   return ans;
    }
};