class Solution {
public:
    // int minPathSum(vector<vector<int>>& grid) {
    //     int n=grid.size();
    //     int m=grid[0].size();
    //     vector<int> dp(m);
    //     dp[0]=grid[0][0];
    //          for(int j=1;j<m;j++){
    //              dp[j]=dp[j-1]+grid[0][j];    
    //      }
    //     for(int i=1;i<n;i++){
    //         for(int j=0;j<m;j++){
    //             // if(i==0 && j==0){
    //             //     dp[j]=grid[i][j];
    //             // }
    //             int up = grid[i][j];
    //             int left = grid[i][j];
    //             if(i>0) up += dp[j];
    //             if(j>0) left += dp[j-1];
    //             dp[j] = min(up,left);
    //         }   
    //     }
    //     return dp[m-1];
    // }
     int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> curr(n+1), prev(n+1, INT_MAX);
        prev[1] = 0;
        curr[0] = INT_MAX;
        for(int i = 1; i <= m; ++i){
            for(int j = 1; j <= n; ++j){
                curr[j] = min(curr[j-1], prev[j]) + grid[i-1][j-1];
            }
            prev = curr;
        }
        return curr[n];
    }

};