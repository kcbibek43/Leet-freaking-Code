//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)  {
        vector<pair<int ,int>> adj[n];
        for(int i=0;i<flights.size();i++){
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        vector<int> dis(n,1e9);
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src,0}});
        dis[src]=0;
        while(!q.empty()){
            int node = q.front().second.first;
            int cost = q.front().second.second;
            int stop = q.front().first;
            q.pop();
            if(stop>K)  continue;
            for(auto it : adj[node]){
                int adjNode = it.first;
                int costNode = it.second;
                if(dis[adjNode] > costNode+cost && stop<=K){
                    dis[adjNode] = costNode + cost;
                    q.push({stop+1,{adjNode,dis[adjNode]}});
                }
            }
        }
        if(dis[dst]==1e9)    return -1;
        return dis[dst];
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> flights;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }
        
        int src,dst,k;
        cin>>src>>dst>>k;
        Solution obj;
        cout<<obj.CheapestFLight(n,flights,src,dst,k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends