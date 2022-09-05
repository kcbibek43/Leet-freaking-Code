class Solution {
public:
    int subsetXORSum(vector<int>& nums){
        if(nums.size()==1){
            return nums[0];
        }
        int n = nums.size();
        int sum = 0;
        for(int i =1;i<(1<<n);i++){
            int xOr=0;
            for(int j =0;j<n;j++){
      if(i&(1<<j)){
          xOr = xOr^nums[j];
      }
            }
            sum+=xOr;
        }
        return sum;
    }
};