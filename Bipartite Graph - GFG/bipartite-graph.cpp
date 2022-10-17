//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool dfs(vector<int>& c,vector<int> adj[],int col,int node){
        c[node] = col;
        for(auto i : adj[node]){
            if(c[i]==-1){
                if(!dfs(c,adj,!col,i))  return false;
            }
            else if(c[i]==col){
                return false;
            }
        }
        return true;
    }
	bool isBipartite(int V, vector<int>adj[]){
	    vector<int> c(V,-1);
	   for(int i=0;i<V;i++){
	       if(c[i]==-1){
	           if(!dfs(c,adj,0,i)){
	               return false;
	           }
	       }
	   }
	   return true;
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
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends