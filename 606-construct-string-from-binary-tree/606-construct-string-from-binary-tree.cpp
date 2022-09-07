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
    void preorder(TreeNode* root,string &s){
        if(root == NULL){
            return;
        }
        if(root->left==NULL && root->right==NULL){
            s+=to_string(root->val);
            return;
        }
         // s+=(root->val);
    //     s+="(";
    // if(root->left == NULL){
    //           s+="()";
    //                 return ;
    //             }
    //   else  preorder(root->left,s);
       if(root->right==NULL){
      s+=to_string(root->val);
         s+="(";
           preorder(root->left,s);
           s+=")";
           return;
       }
     s+=to_string(root->val);
        s+="(";
        preorder(root->left,s);
        s+=")";
        s+="(";
        preorder(root->right,s);
        s+=")";
    }
    string tree2str(TreeNode* root) {
        string s="";
        preorder(root,s);
        cout<<s<<"";
        // return "";
        return s;
        // if(t==NULL){
        //  return "";
        // }
        //  if(t->left==NULL && t->right==NULL)
        //     return char(t->val)+"";
        // if(t.right==NULL)
        //     return char(t->val)+"("+tree2str(t->left)+")";
        // return char(t->val)+"("+tree2str(t->left)+")("+tree2str(t->right)+")"; 
        
    }
};