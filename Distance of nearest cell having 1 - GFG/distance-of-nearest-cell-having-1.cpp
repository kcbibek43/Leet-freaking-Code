//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>> mat){
	   // int n=grid.size();
	   // int m=grid[0].size();
	   // vector<vector<int>> ans(n,vector<int>(m,0));
    //     vector<vector<int>> vis(n,vector<int>(m,0));
        
    //     queue<pair<pair<int,int>,int>> q;
    //     for(int i=0;i<n;i++){
    //         for(int j=0;i<m;j++){
    //             if(grid[i][j]==1){
    //                 vis[i][j]=1;
    //                 q.push({{i,j},0});
    //             }
    //             else vis[i][j]=0;
    //         }
    //     }
    //     int r[]={-1,0,1,0};
    //     int c[]={0,1,0,-1};
    //     while(!q.empty()){
    //         int rr=q.front().first.first;
    //         int cc=q.front().first.second;
    //         int step=q.front().second;
    //         q.pop();
    //         ans[rr][cc]=step; 
    //         for(int i=0;i<4;i++){
    //             int nr = rr+r[i];
    //             int nc = cc+c[i];
    //             if(nr>=0 && nr<n && nc<m && nc>=0 && vis[nr][nc]==0){
    //                 vis[nr][nc]=1;
    //                 q.push({{nr,nc},step+1});
    //             }
    //         }
    //     }
    //     return ans;
      int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> ans(n,vector<int>(m,0));
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==1){
                    vis[i][j]=1;
                    q.push({{i,j},0});
                }
                else{
                    vis[i][j]=0;
                }
            }
        }
        int r[]={0,0,1,-1};
        int c[]={1,-1,0,0};
        while(!q.empty()){
            int rc = q.front().first.first;
            int cc = q.front().first.second;
            int step = q.front().second;
            q.pop();
            ans[rc][cc] = step;
            for(int i=0;i<4;i++){
                int row = rc+r[i];
                int col = cc+c[i];
                if(row>=0 && row<n && col>=0 && col<m && vis[row][col]==0){
                    vis[row][col]=1;
                    q.push({{row,col},step+1});
                }
            }
        }
        return ans; 
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends