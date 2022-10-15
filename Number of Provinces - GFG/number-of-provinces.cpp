//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
   void dfs(int node,vector<int> adj[],vector<int> &v){
     v[node] = 1;
     for(auto it:adj[node]){
         if(!v[it]){
             dfs(it,adj,v);
         }
     }
 }
    int numProvinces(vector<vector<int>> isConnected, int V) {
        int n=V;
        vector<int> adj[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
             if(isConnected[i][j]==1 && i!=j){
                 adj[i].push_back(j);
                 adj[j].push_back(i);
             }
            }
        }
       vector<int> v(n,0);
        int cnt=0;
        for(int i=0;i<n;i++){
          if(!v[i]){
              cnt++;
              dfs(i,adj,v);
          }
        } 
        return cnt;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends