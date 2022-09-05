class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
       int n = nums.size();
        ans.push_back({});
        if(n==1){
            ans.push_back({nums[0]});
            return ans;
        }
     for(int i=1;i<(1<<n);i++){
         vector<int> row;
   int j=0, mask=i;
            while(mask){
                if(mask&1)
                    row.push_back(nums[j]);
                mask>>=1, j++;
         }
         ans.push_back(row);
     }
        return ans;
    }
};