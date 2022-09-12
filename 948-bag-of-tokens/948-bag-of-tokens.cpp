class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
     sort(tokens.begin(),tokens.end());
        int low=0;
        int high=tokens.size()-1;
        int count=0;
        int ans=0;
        while(low<=high && (power>=tokens[low] || count>0)){
            while(low<=high && power >= tokens[low]){
                power-=tokens[low];
                low++;
                count++;
            }
            ans = max(ans,count);
            if(low<=high && count>0){
                power += tokens[high];
                    high--;
                count--;
            }
        }
        return ans;
    }
};