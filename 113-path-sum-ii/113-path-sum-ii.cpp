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
    vector <vector <int>> ans;
    inline void helper (TreeNode* root, int targetSum, vector <int> tmp) {
        if (root == NULL) {
            if (targetSum == 0) {
                ans.push_back (tmp);
            }
            return;
        }
        
        tmp.push_back (root -> val);
        if (root -> left and root -> right) {
            helper (root -> left, targetSum - root -> val, tmp);
            helper (root -> right, targetSum - root -> val, tmp);
        }
        else if (root -> right) helper (root -> right, targetSum - root -> val, tmp);
        else helper (root -> left, targetSum - root -> val, tmp);
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        if (root == NULL) return ans;
        
        vector <int> tmp;
        helper (root, targetSum, tmp);
        
        return ans;
    }
};