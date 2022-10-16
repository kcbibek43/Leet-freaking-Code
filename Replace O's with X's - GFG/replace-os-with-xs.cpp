//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
int r[4] ={-1,0,1,0};
int c[4] ={0,1,0,-1};
  void dfs(vector<vector<char>>& mat,int n,int m,int rr,int cc){
      mat[rr][cc] = 'Y';
        for(int i=0;i<4;i++){
            int nr = rr+r[i];
            int nc = cc+c[i];
        if(nr>=0 && nr<n && nc>=0 && nc<m && mat[nr][nc]== 'O'){
            dfs(mat,n,m,nr,nc);
        }
        }
  }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat){
        
        for(int i=0;i<m;i++){
            if( mat[0][i]=='O'){
                dfs(mat,n,m,0,i);
            }
            if( mat[n-1][i]=='O'){
                dfs(mat,n,m,n-1,i);
            }
        }
        for(int i=0;i<n;i++){
            if( mat[i][0]=='O'){
                dfs(mat,n,m,i,0);
            }
            if( mat[i][m-1]=='O'){
                dfs(mat,n,m,i,m-1);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if( mat[i][j]=='O'){
                    mat[i][j]='X';
                }
                if(mat[i][j]=='Y'){
                    mat[i][j]='O';
                }
            }
        }
       return mat; 
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends