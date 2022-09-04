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
    void find(TreeNode* node,int x,vector<pair<int,int>> &a){
        if(node==NULL){
            return;
        }
        a.push_back(make_pair(x,node->val));
        find(node->left,x-1,a);
        find(node->right,x+1,a);
        
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
//         vector<pair<int,int>> a;
//         find(root,0,a);
//         sort(a.begin(),a.end());
//         for(int i = 0;i<a.size();i++){
//             cout<<a[i].first<<" "<<a[i].second<<"\n";
//         }
//         vector<vector<int>> b;
//         vector<int> ans;
//         // ans.push_back(a[0].second);
//         for(int i = 0; i<a.size();i++){
            
//         }
//         return b;
     map<int , map<int,multiset<int>>> nodes;
        queue<pair<TreeNode*,pair<int,int>>> todo;
        todo.push({root,{0,0}});
        while(!todo.empty()){
            auto p = todo.front();
            todo.pop();
            TreeNode* node = p.first;
            int x = p.second.first,y=p.second.second;
            nodes[x][y].insert(node->val);
            if(node->left){
                todo.push({node->left,{x-1,y+1}});
            }
            if(node->right){
                todo.push({node->right,{x+1,y+1}});
            }
        }
        vector<vector<int>> ans;
        for(auto p:nodes){
            vector<int> col;
            for(auto q : p.second){
                col.insert(col.end(),q.second.begin(),q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};