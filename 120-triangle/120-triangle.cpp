class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        // int m=triangle.size();
        // int sum=triangle[0][0];
        // int idx=0;
        // for(int i=1;i<m;i++){
        //     if(idx==triangle[1].size()-1){
        //         sum+=triangle[i][idx];
        //     }
        //     else{
        //         if(triangle[i][idx]>triangle[i][idx+1]){
        //           sum+=triangle[i][idx+1];
        //             idx=idx+1;
        //         }
        //         else{
        //                sum+=triangle[i][idx];  
        //         }
        // }
        // }
        // return sum;
        int m=triangle.size();
        vector<int> front(m,0);
         vector<int> cur(m,0);
        for(int j=0;j<m;j++){
        front[j]=triangle[m-1][j];
        }
        for(int i=m-2;i>=0;--i){
            for(int j=i;j>=0;--j){
              int dp=triangle[i][j]+front[j];
                int dp2=triangle[i][j]+front[j+1];
                cur[j]=min(dp,dp2);
            }
        front=cur;
        }
        return front[0];
    }
};