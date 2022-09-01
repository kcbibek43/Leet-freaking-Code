class Solution {
public:
    int mySqrt(int x) {
        if(x == 1 || x == 0){
            return x;
        }
        long long int h = x/2;
        long long int l = 0;
        long long int mid = 0;
        while(l<=h){
            mid = (l+h)/2;
            if(x == mid*mid){
                return mid;
            }
            else if(x>mid*mid && x<(mid+1)*(mid+1)){
                return mid;
            }
            else if(x>mid*mid){
                l = mid+1;
            }
            else{
                h = mid-1;
            }
        }
           return 0;
    }
};