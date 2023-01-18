//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    private: 
    void dfs(vector<int> adj[],stack<int>& st,vector<int> &vis,int node){
        vis[node] = 1;
        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(adj,st,vis,it);
            }
        }
        st.push(node);
    }
    private: 
    void dfs3(vector<int> adjR[],vector<int> &vis,int node){
        vis[node] = 1;
        for(auto it : adjR[node]){
            if(!vis[it]){
                dfs3(adjR,vis,it);
            }
        }
    }
	public:
    int kosaraju(int V, vector<int> adj[])
    {
      stack<int> st;
      vector<int> vis(V,0);
      for(int i=0;i<V;i++){
       if(!vis[i]){
           dfs(adj,st,vis,i);
       }   
      }
      vector<int> adjR[V];
      for(int i=0;i<V;i++){
          vis[i]=0;
          for(auto it : adj[i]){
              adjR[it].push_back(i);
          }
      }
      int scc = 0;
      while(!st.empty()){
          int node = st.top();
          st.pop();
        if(!vis[node]){
            scc++;
    dfs3(adjR,vis,node);   
        }
      }
      return scc;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends