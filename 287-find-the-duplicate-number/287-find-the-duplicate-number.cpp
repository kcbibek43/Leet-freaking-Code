class Solution {
public:
    int findDuplicate(vector<int>& nums) {
    //  int prev=0;
    //     int xOr=nums[0];
    //     int ans=0;
         int n=nums.size();
    //     for(int i=1;i<n;i++){
    //      // xOr=xOr^nums[i];
    //     if((prev^nums[i])==xOr || (nums[i]^nums[i-1])==0){
    //         ans = nums[i];
    //         break;
    //     }
    // xOr=xOr^nums[i];
    // prev = xOr;
    //     }
    //     return ans;
        //  unordered_set<int> seen;
        // for (auto &num : nums) {
        //     if (seen.count(num))
        //         return num;
        //     seen.insert(num);
        // }
        // return -1;
        set<int> st;
        st.insert(nums[0]);
        for(int i=1;i<n;i++){
            if(st.find(nums[i])!=st.end()){
        return nums[i];
            }
            st.insert(nums[i]);
        }
        return -1;
    }
};