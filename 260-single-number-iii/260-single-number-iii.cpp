class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xOr=0;
        for(int i =0;i<nums.size();i++){
            xOr = xOr^nums[i];
        }
        int cnt=0;
        while(xOr){
            if(xOr&1){
                break;
            }
            cnt++;
            xOr =xOr>>1;
        }
        int xOr1=0,xOr2=0;
        for(int i =0;i<nums.size();i++){
            if(nums[i] & (1<<cnt)){
                xOr1 = xOr1^nums[i];
            }
            else{
           xOr2 = xOr2 ^ nums[i];
            }
        }
        vector<int> ans;
        ans.push_back(xOr1);
        ans.push_back(xOr2);
        return ans;
    }
};