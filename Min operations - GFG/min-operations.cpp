//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int solve(int a, int b) {
       if( a == b) return 0;
      int mx = max(a,b);
      int mn = min(a,b);
       bool flag = false;
      for(int i=0;i<32;i++){
              if(mx & 1<<i){
                  continue;
              }
              else{
                  if(mn & 1<<i){
                      flag = true;
                      break;
                  }
              }
      }
      if (flag)
      return 2;
      return 1;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int a;
        scanf("%d",&a);
        
        
        int b;
        scanf("%d",&b);
        
        Solution obj;
        int res = obj.solve(a, b);
        
        printf("%d\n", res);
        
    }
}

// } Driver Code Ends