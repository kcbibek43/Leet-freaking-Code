class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
     set<vector<int>> ans;
        sort(nums.begin(),nums.end());
       int n = nums.size();
     for(int i=0;i<(1<<n);i++){
         vector<int> row;
         for(int j=0;j<n;j++){
             if(i&(1<<j)){
                 row.push_back(nums[j]);
             }
         }
         ans.insert(row);
     }
        vector< vector<int> > res;
        for (auto x: ans) {
            res.push_back(x);
        }
        return res;
    }
};