class Solution {
public:
    // int binary(vector<int> nums,int k,int low,int high){
    //     if(low>high){
    //         return -1;
    //     }
    //     int ans = 0;
    //     int mid=(low+high)/2;
    //         if(nums[mid]==k){
    //           return mid;
    //         }
    //         else if(nums[mid]<k){
    //            return binary(nums,k,mid+1,high);
    //         }
    //            return binary(nums,k,low,mid-1);
    // }
    int search(vector<int>& nums, int target) {
       int n = nums.size()-1;
        int l = 0;
        int h = n;
        int mid =0;
        while(l<=h){
            mid=(l+h)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]<target){
                l = mid+1;
            }
            else{
                h = mid-1;
            }
        }
     
        return -1;
        // return binary(nums,target,0,nums.size()-1);
    }
};