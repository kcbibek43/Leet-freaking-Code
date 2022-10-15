//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
//   void find1(vector<vector<char>>& grid,int x,int y,int n,int m){
//     if(x<0 || y<0 || x>=n || y>=m || grid[x][y]!='1'){
//     return; 
//     }
//     grid[x][y]='2';
//     find1(grid,x+1,y,n,m);
//     find1(grid,x,y+1,n,m);
//     find1(grid,x-1,y,n,m);
//     find1(grid,x,y-1,n,m);
//   }
 void find_island(int x,int y,vector<vector<char>>& grid,int r,int c){
     if(x<0 || y<0 || x>=r || y>=c || grid[x][y] != '1'){
     return ;
     }
        grid[x][y]='2';
        find_island(x,y+1,grid,r,c);
        find_island(x+1,y,grid,r,c);
        find_island(x-1,y,grid,r,c);
        find_island(x,y-1,grid,r,c);
        find_island(x+1,y-1,grid,r,c);
         find_island(x-1,y-1,grid,r,c);
          find_island(x+1,y+1,grid,r,c);
        find_island(x-1,y+1,grid,r,c);
    }
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // int n = grid.size();
        // int m = grid[0].size();
        // int count =0;
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;i++){
        //      if(grid[i][j]=='1'){
        //          count++;
        //          find1(grid,i,j,n,m);
        //      }
        //     }
        // }
        // return count;
       int row = grid.size();
        if(row == 0){
            return 0;
        }
        int island = 0;
        int col = grid[0].size();
        for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
        if(grid[i][j]=='1'){
            find_island(i,j,grid,row,col);
            island+=1;
        }
        }
        }
        return island;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends