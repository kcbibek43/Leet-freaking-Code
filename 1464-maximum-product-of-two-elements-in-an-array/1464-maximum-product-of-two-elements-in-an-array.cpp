class Solution {
public:
    int maxProduct(vector<int>& nums) {
     priority_queue<int> p;
        for(int i =0;i<nums.size();i++){
            p.push(nums[i]);
        }
    int a = p.top();
        p.pop();
    int b = p.top();
        return (a-1) * (b-1);
        // int n = nums.size();
        // sort(nums.begin(),nums.end());
        // return (nums[n-1]-1)*(nums[n-2]-1);
    }
};