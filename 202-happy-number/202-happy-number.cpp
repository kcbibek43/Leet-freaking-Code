class Solution {
public:
    unordered_set<int> st;
    bool isHappy(int n) {
        if(n==1){
            return true;
        }
        if(st.find(n)!=st.end()){
            return false;
        }
        st.insert(n);
        int sum = 0;
        while(n!=0){
            int m = n%10;
            sum+=m*m;
            n=n/10;
        }
        return isHappy(sum);
    }
};