//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
      stack<char> st;
    //   int n = x.length();
    //   if(x[0]==')' || x[0]=='}' || x[0]==']' || n%2==1){
    //       return false;
    //   }
    //   for(int i=0;i<n;i++){
    //       if(x[i]=='(' || x[i]=='{' || x[i]=='['){
    //           st.push(x[i]);
    //       }
    //       else{
    //     if(x[i]==')' && st.top()=='('){
    //           st.pop();
    //       }
    //      else if(x[i]=='}' && st.top()=='{'){
    //          st.pop();
    //      }
    //      else if(x[i]==']' && st.top()=='['){
    //          st.pop();
    //      }
    //      else{
    //          return false;
    //      }
    // }
    //   }
    //   return true;
    for(auto it: x) {
            if(it=='(' || it=='{' || it == '[') st.push(it); 
            else {
                if(st.size() == 0) return false; 
                char ch = st.top(); 
                st.pop(); 
                if((it == ')' and ch == '(') or  (it == ']' and ch == '[') or (it == '}' and ch == '{')) continue;
                else return false;
            }
        }
        return st.empty();
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends