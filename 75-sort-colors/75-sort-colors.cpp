class Solution {
public:
    void sortColors(vector<int>& nums) {
     int a=0,b=0;
        for(int i =0;i<nums.size();i++){
            if(nums[i]==0) a++;
            if(nums[i]==1) b++;
        }
        for(int i = 0 ; i<a ;i++){
            nums[i]=0;
        }
        for(int i = a;i<a+b;i++)  nums[i]=1;
        for(int i = (a+b);i<nums.size();i++)  nums[i]=2;
    }
};