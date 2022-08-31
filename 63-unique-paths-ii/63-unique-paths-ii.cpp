class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid){
        // int col=0;
        // int row=0;
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        // for(int i=0;i<obstacleGrid.size();i++){
        //  for(int j=0;j<obstacleGrid[i].size();j++){
        //      if(obstacleGrid[i][j]==1){
        //          col=j;
        //          row=i;
        //          break;
        //      }
        //  }
        // }
 vector<int> dp1(n,0);
        dp1[0]=1;
        // for(int i=0;i<m;i++){
        //  for(int j=0;j<n;j++){
        //      if(obstacleGrid[i][j]==1){
        //          dp1[j]= 0;
        //      }
        //      else if(i==0 && j==0){
        //     dp1[j]=1;
        //      }
        //      else{
        //           int left=0;
        //          int up=0;
        //          if (i>0) up=dp1[j];
        //           if(j>0) left = dp1[j-1];
        //          dp1[j]=left+up;
        //      }
        //  }
        //  } 
        // return dp1[n-1]; 
         vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(obstacleGrid[i][j] == 1){
                    dp[i][j] = 0;
                }else if(i == 0 && j == 0){
                    dp[i][j] = 1;
                }else{
                    int w1 = 0; 
                    int w2 = 0;
                    if(i > 0){
                        w1 = dp[i - 1][j];
                    }
                    if(j > 0){
                        w2 = dp[i][j - 1];
                    }
                    dp[i][j] = w1 + w2;
                }
            }
        }
            return dp[n-1][m-1];
        }
};