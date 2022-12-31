//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int minLaptops(int N, int start[], int end[]) {
        int ans = 0;
     vector<pair<int,int>> v;
        for(int i=0;i<N;++i){
            v.push_back({start[i],1});
            v.push_back({end[i],-1});
        }
        sort(v.begin(),v.end());
        int cur = 0;
        for(auto i: v){
            cur = cur + i.second;
            ans = max(ans,cur);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int start[N], end[N];
        for(int i=0; i<N; i++)
            cin>>start[i];
        for(int i=0; i<N; i++)
            cin>>end[i];
            
        Solution ob;
        cout << ob.minLaptops(N, start, end) << endl;
    }
}
// } Driver Code Ends