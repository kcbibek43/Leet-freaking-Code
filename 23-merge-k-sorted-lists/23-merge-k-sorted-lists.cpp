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
    ListNode* newnode = new ListNode(k);
      newnode->val = k;
      node->next = newnode;
    newnode->next = NULL;
     }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0){
            return NULL;
        }
        list<int> l1;
        list<int> l2;
        // while(lists[0]!=NULL){
        //     l1.push_back(lists[0]->val);
        //     lists[0]=lists[0]->next;
        // }
        for(int a=0;a<lists.size();a++){
           if(lists[a]!=NULL){
            while(lists[a]!=NULL){
                l2.push_back(lists[a]->val);
                lists[a]=lists[a]->next;
            }
            l1.merge(l2);
            l2.clear();
           }
        }
     //    for(auto i = l1.begin();i!=l1.end();i++){
     // cout<<*i<<" ";
     //    }
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
        if(head->val == 0 && head->next == NULL){
            return NULL;
        }
        return head;
    }
};