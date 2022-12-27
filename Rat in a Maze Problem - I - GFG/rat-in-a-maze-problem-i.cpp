//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    int r[4] ={-1,0,1,0}; 
    int c[4] ={0,-1,0,+1}; 
    string dir = "ULDR";
    vector<string> findPath(vector<vector<int>> &m, int n) {
        if(!m[0][0]){
            return {};
        }
        vector<string> ans;
        string node = "";
        vector<vector<int>> vis(n,vector<int>(n,0));
        findMaze(ans,node,vis,m,n,0,0);
        return ans;
    }
    void findMaze(vector<string> &ans,string node,vector<vector<int>> &vis,vector<vector<int>> m,int n,int row,int col){
        if(row == n-1 && col == n-1){
            ans.push_back(node);
            return;
        }
       for(int i=0;i<4;i++){
           int nr = row + r[i];
           int nc = col + c[i];
           if(nc>=0 && nc<n && nr>=0 && nr<n && !vis[nr][nc] && m[nr][nc]){
                vis[row][col] = 1;
               findMaze(ans,node+dir[i],vis,m,n,nr,nc);
                vis[row][col] = 0;
           }
       }
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends