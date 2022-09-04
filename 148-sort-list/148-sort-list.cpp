/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
       void insert(ListNode* node,int k){
//             ListNode* new_node = new ListNode();
   
//     // Used in step 5
//     ListNode* last = node;
   
//     // 2. Put in the data
//     new_node->val = new_data; 
   
//     // 3. This new node is going to be 
//     // the last node, so make next of 
//     // it as NULL
//      new_node->next = NULL; 
      ListNode* newnode = new ListNode(k);
      newnode->val = k;
      node->next = newnode;
    newnode->next = NULL;
     }
    ListNode* sortList(ListNode* root) {
        list<int> l1; 
        if(root == NULL){
            return root;
        }
        ListNode* tm = root; 
        while(tm!=NULL){
            l1.push_back(tm->val);
            tm=tm->next;
        }
        l1.sort();
        ListNode* head = new ListNode(l1.front());
        head->val = l1.front();
        auto ir = l1.begin();
        ir++;
        ListNode* temp = head;
        for(auto it = ir; it!=l1.end();it++){
            // cout<<*it<<" ";
       insert(temp,*it);
            temp=temp->next;
        }
        return head;
    }
};