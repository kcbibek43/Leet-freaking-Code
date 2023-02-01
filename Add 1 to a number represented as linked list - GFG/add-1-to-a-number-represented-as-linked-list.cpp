//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
 Node* reverse(Node* head)
    {
        if (head == NULL || head->next == NULL)
            return head;
 
        Node* rest = reverse(head->next);
        head->next->next = head;
 
        head->next = NULL;
 
        return rest;
    }
     Node *lastNode = NULL;
    Node* addOne(Node *head) 
    {
        int val = 0;
        Node* ans = reverse(head);
        Node* cur = ans;
        int carry = 1;
        while(cur!=NULL){
            if(cur->data == 9 && carry == 1){
                cur->data = 0;
                val = cur->data;
                carry = 1;
            }
            else{
                cur->data += carry;
                val = cur->data;
                carry = 0;
            }
            if(cur->next == NULL)
            lastNode = cur;
            cur = cur->next;
            if(cur==NULL && val == 0){
                Node* node = new Node(1);
                node->data = 1;
                lastNode->next = node;
               // node->next = NULL;
                break;
            }
        }
        Node* res = reverse(ans);
        return res;
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends