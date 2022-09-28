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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count=0;
        ListNode* temp = head;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        if(count == 1){
            return NULL;
        }
        ListNode* gd=head;
        if(count==n){
            return head->next;
        }
   int ct = count-n-1;
    while(ct--){
            gd=gd->next;
        }
        ListNode*  nt;
        nt = gd->next;
        gd->next=nt->next;
        return head;
    }
};