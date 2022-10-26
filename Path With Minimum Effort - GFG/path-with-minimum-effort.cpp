//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& heights) {
      int n = heights.size();
      int m = heights[0].size();
    int row[] = {-1,0,1,0};
     int col[] = {0,1,0,-1};
      priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
      pq.push({0,{0,0}});
      vector<vector<int>> dis(n,vector<int>(m,1e9));
      dis[0][0];
      while(!pq.empty()){
          int r = pq.top().second.first;
          int c = pq.top().second.second;
          int diff = pq.top().first;
          pq.pop();
          if(r==n-1 && c==m-1){
             return diff;
          }
          for(int i=0;i<4;i++){
              int nr = r+row[i];
              int nc = c+col[i];
              if(nr>=0 && nr<n && nc>=0 && nc<m ){
                  int newEffort = max(abs(heights[r][c]-heights[nr][nc]),diff);
                  if(newEffort < dis[nr][nc]){
                      dis[nr][nc] = newEffort;
                      pq.push({newEffort,{nr,nc}});
                  }
              }
          }
      }
      return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends