class Solution
{
    public:

        int findprofit(int i, vector<int> &p, int b, int k, vector<vector< vector< int>>> &dp)
        {
            if (k < 1 || i == p.size()) return 0;
            int profit = 0;
            int take = 0, nottake = 0;
            if (dp[i][b][k] != -1) return dp[i][k][b];
            if (b)
            {
                take = -p[i] + findprofit(i + 1, p, 0, k, dp);
                nottake = findprofit(i + 1, p, 1, k, dp);
            }
            else
            {
                take = p[i] + findprofit(i + 1, p, 1, k - 1, dp);
                nottake = findprofit(i + 1, p, 0, k, dp);
            }
           	// cout<<max(take,nottake)<<endl;
            return dp[i][b][k] = max(take, nottake);
        }
    int maxProfit(int k, vector<int> &prices)
    {
        vector<vector<vector< int>>> dp(prices.size() + 1, vector<vector < int>> (2, vector<int> (k+1, 0)));
int take ,nottake;
        for (int i = prices.size() - 1; i >= 0; i--)
        {
            for (int b = 0; b <= 1; b++)
            {
                for (int k1 = 1; k1 <= k; k1++)
                {
                    if (b)
                    {
                        take = -prices[i] +  dp[i + 1][0][k1];
                        nottake =  dp[i + 1][1][k1];
                    }
                    else
                    {
                        take = prices[i] + dp[i + 1][1][k1 - 1];
                        nottake = dp[i + 1][0][k1];
                    }
                
                     dp[i][b][k1] = max(take, nottake);
                }
                
            }
        }
        return dp[0][1][k];
    }
};

//vector<vector < int>>dp(prices.size()+1,vector<int>(k+1,-1));
// vector<int> ans(k,0);
// int buy = 1;
// int profit = 0;
// ans[0]=prices[0];
// for(int i=0;i < prices.size()-1;i++){
//     int take =0;
//     int nottake=0;
//     if(k>0){
//         if(buy){
//             take = -prices[i] + prices[i+1];
//             nottake = prices[i+1]
//                 buy=0;
//         }
//         else{
//             take = prices[i] + ans[i-1];
//             nottake = prices[i+1];
//         }
//     }
// }