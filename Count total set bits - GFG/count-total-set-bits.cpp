//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
    int countLeftMostBit(int n){
        int cnt = 0;
     while(n>0){
         cnt++;
         n>>=1;
     }
     return cnt;
    }
    int countSetBits(int n)
    {
        // int remain = 0;
        // int cnt = 0;
        // int r = 0;
        
        // int mod = 0;
        // int idx = countLeftMostBit(n);
        // for(int i=1;i<=idx;i++){
        //     int id = (pow(2,i));
        //     if(id>n){
        //         int last = pow(2,i-1);
        //         cnt += (n%last+1);
        //     }
        //     else{
        //         if(i==1 && i%2==1){
        //             r = (n+1)/id;
        //             mod = n%2;
        //             remain = 0;
        //             cnt += (n+1)/2; 
        //         }
        //         else{
        //              r = n/id;
        //              mod = n%id;
        //             if(mod>=(id/2)){
        //                 remain = (mod-(id/2)+1);
        //             }
        //             else{
        //                 remain = 0;
        //             }
        //         }
        //         int curr = remain + r*(id/2);
        //         cnt += curr;
        //     }
        // }
        // return cnt;
         int leftMostSetBitInd = countLeftMostBit(n);
 
    int totalRep, mod;
    int nearestPow;
    int totalSetBitCount = 0;
    int addRemaining = 0;
 
    int curr
        = 0; // denotes the number of set bits at index i
 
    // cout<<"leftMostSetBitInd: "<<leftMostSetBitInd<<endl;
 
    for (int i = 1; i <= leftMostSetBitInd; ++i) {
        nearestPow = pow(2, i);
        if (nearestPow > n) {
            int lastPow = pow(2, i - 1);
            mod = n % lastPow;
            totalSetBitCount += mod + 1;
        }
        else {
            if (i == 1 && n % 2 == 1) {
                totalRep = (n + 1) / nearestPow;
                mod = nearestPow % 2;
                addRemaining = 0;
            }
            else {
                totalRep = n / nearestPow;
                mod = n % nearestPow;
 
                if (mod >= (nearestPow / 2)) {
                    addRemaining
                        = mod - (nearestPow / 2) + 1;
                }
                else {
                    addRemaining = 0;
                }
            }
 
            curr = totalRep * (nearestPow / 2)
                   + addRemaining;
            totalSetBitCount += curr;
        }
    }
 
    return totalSetBitCount;
    }
};


//{ Driver Code Starts.

// Driver code
int main()
{
	 int t;
	 cin>>t;// input testcases
	 while(t--) //while testcases exist
	 {
	       int n;
	       cin>>n; //input n
	       Solution ob;
	       cout << ob.countSetBits(n) << endl;// print the answer
	  }
	  return 0;
}

// } Driver Code Ends