class Solution {
public:
     double square(double b,long long int nn){
   if(nn==0){
            return 1;
        }
        double ans  = 1.0;
        while(nn!=0){
            if(nn%2 !=0){
                ans = ans * b;
                nn-=1;
                
            }
            else{
                b = b*b;
                nn = nn/2;
            }
        }
         return ans;
    }
    double myPow(double x, int n) {
        if(n<0){
            return 1.00/square(x,abs(n));
        }
        return square(x,abs(n));
    }
};