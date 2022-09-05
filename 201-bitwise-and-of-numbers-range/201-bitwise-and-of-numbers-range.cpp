class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
     if(left==right){
         return left;
     }   
    if(left==0 || right==0){
            return 0;
        }
//     int n;
//     int n1 = log2(left);
//     int n2 = log2(right);
//         if(n1<n2 ){
//             n=0;
//         }
//         else{
//             for(int i=left;i<=right;i++){
                
//             }
//         }
        int count=0;
        while(left!=right){
            left=left>>1;
            right=right>>1;
            count++;
        }
        int ans = left<<count;
        return ans;
    }
};