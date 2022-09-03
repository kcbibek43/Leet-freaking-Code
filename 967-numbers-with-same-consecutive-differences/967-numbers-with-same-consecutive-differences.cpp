class Solution {
public:
    void dfs(int num,int n,int k,vector<int> &ans){
        if(n==0){
            ans.push_back(num);
            return;
        }
        int lastdigit = num%10;
        if(lastdigit>=k) dfs(num*10 + lastdigit-k , n-1,k,ans);
        if(k>0 && lastdigit+k<10) dfs(num*10 + lastdigit+k,n-1,k,ans);
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans;
    // if (n==1){
    //     return {0,1,2,3,4,5,6,7,8,9};
    // }
        for(int i = 1; i<10 ; i++){
          dfs(i,n-1,k,ans);
        }
        return ans;
    }
};