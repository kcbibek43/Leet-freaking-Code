//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<pair<int,int>> adj[n+1];
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
      priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({1,0});
        vector<int> dis(n+1,1e9);
        vector<int> parent(n+1);
        for(int i=1;i<=n;i++){
            parent[i]=i;
        }
        dis[1] = 0;
      while(!pq.empty()){
          int n = pq.top().first;
          int cost = pq.top().second;
          pq.pop();
          for(auto it : adj[n]){
              int node = it.first;
              int edgeWeight = it.second;
              if(cost + edgeWeight <dis[node]){
                  dis[node] = cost+ edgeWeight;
                  pq.push({node,dis[node]});
                  parent[node] = n;
              }
          }
      }
if(dis[n]==1e9)   return {-1};
      vector<int> ans;
      int node = n;
      while(parent[node] != node){
          ans.push_back(node);
          node = parent[node];
          }
        ans.push_back(1);
        reverse(ans.begin(),ans.end());
          return ans;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
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