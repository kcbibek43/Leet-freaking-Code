class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        if(nums2.size()<nums1.size()) return intersection(nums2,nums1);
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int> ans;
        int i=0;
        int j=0;
        int count=0;
        while(i<n1 && j<n2){
        if(nums1[i]==nums2[j]){
            if(count==0 || nums1[i]!=ans[count-1]){
                ans.push_back(nums1[i]);
                count++;
            }
            i++;
            j++;
        }
            else if(nums1[i]>nums2[j]){
                j++;
            }
            else{
                i++;
            }
        }
        return ans;
    }
};