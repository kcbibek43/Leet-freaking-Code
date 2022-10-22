//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:

     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
       vector<pair<int,int>> adj[N];
       vector<int> dis(N,1e9);
       for(int i=0;i<edges.size();i++){
           int a = edges[i][0];
           int b = edges[i][1];
           int c = edges[i][2];
           adj[a].push_back({b,c});
       }
       dis[0]=0;
       	  vector<int> in(N,0);
	   for(int i=0;i<N;i++){
	       for(auto it : adj[i]){
	           in[it.first]++;
	       }
	   }
	   queue<int> q;
	   for(int i=0;i<N;i++){
	       if(in[i]==0){
	           q.push(i);
	       }
	   } 
	   vector<int> topo;
	   while(!q.empty()){
	       int node = q.front();
	        q.pop();
	        topo.push_back(node);
	       for(auto a : adj[node]){
	           in[a.first]--;
	           if(in[a.first]==0){
	               q.push(a.first);
	           }
	       }
	   }
	   for(int i=0;i<N;i++){
	       int node = topo[i];
	       for(auto it : adj[node]){
	           int m = it.first;
	           int cost = it.second;
	           if(cost+dis[node]<dis[m]){
	               dis[m] = dis[node] + cost; 
	           }
	       }
	   }
	   for(int i=0;i<N;i++){
	       if(dis[i]==1e9)   dis[i] = -1;
	   }
	   return dis;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends