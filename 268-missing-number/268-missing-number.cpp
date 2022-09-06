class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int xOr1=0;
        int xOr2=0;
     for(int i=0;i<n;i++){
         xOr1=xOr1^nums[i];
         xOr2=xOr2^(i+1);
     }   
        int ans = xOr1^xOr2;
        return ans;
    }
};