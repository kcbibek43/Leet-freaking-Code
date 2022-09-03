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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        list<int> l1;
        list<int> l2;
        if(list1==NULL){
            return list2;
        }
        if(list2==NULL){
         return list1;
        }
        while(list1!=NULL){
         l1.push_back(list1->val);
            list1=list1->next;
        }
        while(list2!=NULL){
            l2.push_back(list2->val);
            list2=list2->next;
        }
        l1.merge(l2);
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