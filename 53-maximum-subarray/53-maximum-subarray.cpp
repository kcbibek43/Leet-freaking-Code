class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size(),0);
        if(nums.size()==1){
            return nums[0];
        }
         dp[0] = nums[0];
        for(int i = 1 ; i < nums.size() ; i++ ){
        int sum = nums[i] + dp[i-1];
            dp[i]=max(sum,nums[i]);
        }
        int mx=INT_MIN;
     for(int i = 0;i<dp.size();i++){
         mx=max(dp[i],mx);
     }
        // int sum=0,mx=INT_MIN;
        // for(int i:nums){
        //     sum+=i;
        //     mx=max(mx,sum);
        //     if(sum<0)
        //         sum=0;
        // }
        return mx;
    }
};