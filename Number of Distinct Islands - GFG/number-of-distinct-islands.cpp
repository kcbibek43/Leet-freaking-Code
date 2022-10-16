//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  vector<vector<int> > dirs = { { 0, -1 },
                              { -1, 0 },
                              { 0, 1 },
                              { 1, 0 } };
 
    void find1(vector<vector<int>>& grid,vector<pair<int,int>>& v,int x,int y,int n,int m){
       int n1 = grid.size();
        int m1 = grid[0].size();
    if(x<0 || y<0 || x>=n1 || y>=m1 || grid[x][y]!=1){
    return; 
    }
    
    v.push_back({n-x,m-y});
    grid[x][y]=0;
         for (auto dir : dirs) {
        find1(grid,v,x+dir[0],y+dir[1],n,m);
    }
  }
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n==0){
            return 0;
        }
        int m = grid[0].size();
        if(m==0){
            return 0;
        }
        set<vector<pair<int,int>>> st;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
             if(grid[i][j]==1){
                vector<pair<int,int>> v;
                 find1(grid,v,i,j,i,j);
                 st.insert(v);
             }
            }
        }
        return st.size();
    // int rows = grid.size();
    // if (rows == 0)
    //     return 0;
 
    // int cols = grid[0].size();
    // if (cols == 0)
    //     return 0;
 
    // set<vector<pair<int, int> > > coordinates;
 
    // for (int i = 0; i < rows; ++i) {
    //     for (int j = 0; j < cols; ++j) {
    //         if (grid[i][j] == 1){
    //         vector<pair<int, int> > v;
    //         find1(grid,v, i, j, i, j);
    //         coordinates.insert(v);
    //         }
    //     }
    // }
    // return coordinates.size();
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
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends