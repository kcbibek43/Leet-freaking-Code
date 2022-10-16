//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
   int dfs(vector<vector<int>>& grid ,int n,int m,int r,int c){
          if(r<0 || r>=n || c<0 || c>=m || grid[r][c]==0){
              return 0;
          }
        grid[r][c]=0;
        return 1 + dfs(grid,n,m,r-1,c) + dfs(grid,n,m,r,c-1) + dfs(grid,n,m,r+1,c) + dfs(grid,n,m,r,c+1);
   }
    int numberOfEnclaves(vector<vector<int>>& grid){
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
               if(i==0 || j==0 || i==n-1 || j==m-1){
                   if(grid[i][j]==1){
                dfs(grid,n,m,i,j);
                   }
               }
           }
        }
         int ans=0;
        for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
               ans+=grid[i][j];
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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends