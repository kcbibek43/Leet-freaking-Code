class Solution {
public:
    int uniquePaths(int m, int n) {
     vector<int> dp1(n,0);
        dp1[0]=1;
        for(int i=0;i<m;i++){
        // vector<int> dp1(n,0);
         for(int j=0;j<n;j++){
              if(i==0 && j==0){
         dp1[j]=1;
              }
              else{
                  int left=0;
                  if(j>0) left = dp1[j-1];
                 dp1[j]=left+dp1[j];
         }
         }
            // dp=dp1;
     }   
        return dp1[n-1];
    }
};