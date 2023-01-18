//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
private:
int timer = 1;
    void dfs(vector<int> adj[],vector<int>& vis,vector<int>& mark,int node,int parent,
    vector<int>& tin,vector<int>& low){
        vis[node] = 1;
        low[node] = timer;
        tin[node] = timer;
        timer++;
        int child = 0;
        for(auto it : adj[node]){
           if(it == parent ) continue;
           if(!vis[it]){
             dfs(adj,vis,mark,it,node,tin,low);
              low[node] = min(low[node],low[it]); 
              if(low[it]>=tin[node] && parent != -1){
                  mark[node] = 1; 
              }
        child++;
           }
           else{
               low[node] = min(low[node],tin[it]);
           }
        }
        if(child > 1 && parent == -1){
            mark[node] = 1;
        }
    }    
  public:
    vector<int> articulationPoints(int n, vector<int>adj[]) {
    vector<int> mark(n,0);
    vector<int> vis(n,0);
    vector<int> tin(n,0);
    vector<int> low(n,0);
    vector<int> ans;
       dfs(adj,vis,mark,0,-1,tin,low);
       for(int i=0;i<n;i++){
           if(mark[i]){
               ans.push_back(i);
           }
       }
       if(ans.size()==0)  return {-1};
     return ans;
    }
};

//{ Driver Code Starts.

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends