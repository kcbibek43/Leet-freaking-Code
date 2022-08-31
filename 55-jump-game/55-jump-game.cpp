class Solution {
public:
    bool canJump(vector<int>& nums) {
    //     int m=nums.size();
    //     vector<int> memo(m,0);
    //     memo[0]=nums[0];
    //     if(memo[0]==0){
    //         return m==1;
    //     }
    //     for(int i=1;i<m-1;++i){
    //         memo[i]= max(nums[i],memo[i]-1);
    //      if(memo[i]==0){
    //          return false;
    //      }
    //     }
    //     return true;
    // }
        int size = nums.size();
        vector<int> memo(size,0);
        memo[0] = nums[0];
        if (memo[0] == 0) {
			return size == 1; 
		}
        for (int i = 1; i < size - 1; ++i) {
            memo[i] = max(memo[i-1]-1, nums[i]); 
            if (memo[i] == 0) return false; 
        }
        return true;  
} 
};