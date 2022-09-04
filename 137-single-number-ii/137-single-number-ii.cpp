class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // set<int> st;
        // int num = 0;
        // for(int i=0;i<nums.size();i++){
        //     num=nums[i]^num;
        //     st.insert(nums[i]);
        // }
        // for(auto it=st.begin();it!=st.end();it++){
        //     num = num ^ (*it);
        // }
        // return num;
        int ones = 0;
        int twos = 0;
        for(auto a : nums){
            ones=(ones^a) & (~twos);
            twos=(twos^a) & (~ones);
        }
        return ones;
    }
};