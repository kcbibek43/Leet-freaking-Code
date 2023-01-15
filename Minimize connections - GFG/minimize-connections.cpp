//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class DisjointSet{
    public:
    vector<int> rank,parent;
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
    }
    int findParent(int u){
        if(u == parent[u]){
            return u;
        }
        return parent[u] = findParent(parent[u]);
    }
    void unionByRank(int node,int adjNode){
        int u = findParent(node);
        int v = findParent(adjNode);
        if(u == v)  return;
        if(rank[u]>rank[v]){
            parent[v] = u;
        }
        else if(rank[u] < rank[v]){
            parent[u] = v;
        }
        else{
            parent[v] = u;
            rank[u]++;
        }
    }
};
class Solution{
    public:
        int minimumConnections(vector<vector<int>> &c,int n)
        {
            DisjointSet ds(n);
            int cntExtra = 0;
          for(auto x : c){
              int u = x[0];
              int v = x[1];
              if(ds.findParent(u)==ds.findParent(v)){
                  cntExtra++;
              }
              else{
                  ds.unionByRank(u,v);
              }
          }
          int cnt = -1;
          for(int i=0;i<n;i++){
              if(ds.parent[i] == i){
                  cnt++;
              }
          }
          if(cntExtra<cnt) return -1;
          return cnt;
        }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int m;
        cin>>m;
        vector<vector<int>> c(m,vector<int> (2));
        for(auto &j:c)
            cin>>j[0]>>j[1];
        Solution s;
        cout<<s.minimumConnections(c,n)<<endl;
    }
    return 0;
}
// } Driver Code Ends