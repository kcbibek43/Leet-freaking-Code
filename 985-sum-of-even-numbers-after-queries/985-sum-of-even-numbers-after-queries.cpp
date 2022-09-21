class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
         int even_sum = 0;
    
    for(int i=0;i<nums.size();i++){
        if(!(nums[i]&1)){
            even_sum += nums[i];
        }
    }
    vector<int>ans(queries.size(),0);
    
    for(int i=0;i<queries.size();i++){
        int val = queries[i][0];
        int ind = queries[i][1];
        
        if(nums[ind]%2==0 and (nums[ind]+val)%2==0){
            even_sum += val;
        }
        else if(nums[ind]%2!=0 and (nums[ind]+val)%2==0){
            even_sum += (nums[ind]+val);
        }
        else if(nums[ind]%2==0){
            even_sum -= nums[ind];
        }
        nums[ind] += val;
        
        ans[i] = even_sum;
    }        
    return ans; 
    }
};