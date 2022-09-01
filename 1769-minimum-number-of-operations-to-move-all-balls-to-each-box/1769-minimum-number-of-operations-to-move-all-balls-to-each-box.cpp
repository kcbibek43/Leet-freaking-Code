class Solution {
public:
    vector<int> minOperations(string boxes) {
        int len = boxes.length();
        vector<int> ans;
        for(int i=0;i<len;i++){
            int sum =0;
        for(int j=0;j<len;j++){
            if(j!=i && boxes[j]=='1'){
                sum+=abs(i-j);
            }
        }
            ans.push_back(sum);
        }
        return ans;
    }
};