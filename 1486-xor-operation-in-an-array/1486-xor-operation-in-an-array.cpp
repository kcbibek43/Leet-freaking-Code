class Solution {
public:
    int xorOperation(int n, int start) {
        int ans=0;
        int a=0;
        for(int i=0;i<n;i++){
            a=start+i*2;
            ans^=a;
        }
        return ans;
    }
};