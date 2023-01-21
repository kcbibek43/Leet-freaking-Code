//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minVal(int a, int b) {
        int cnt = __builtin_popcount(b);
        int cnt2 = __builtin_popcount(a);
        if(cnt == cnt2 ) return a;
        int st = cnt;
        int x = a;
        int ans = 0;
    if(cnt>cnt2){
        for(int i=0;i<32;i++){
            if(st==0) break;
         if(st<=cnt2){
             if(a&(1<<i)){
             ans += (1<<i);
             st--;
             }
         }
         else{
             
             if(a&(1<<i))  cnt2--;
             ans+=(1<<i);
             st--;
         }
        }
    }
    else{
        for(int i=31;i>=0;i--){
            if(st==0) break;
            if(a&(1<<i)){
                ans+=(1<<i);
                st--;
            }
        }
    }
    return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.minVal(a, b);

        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends