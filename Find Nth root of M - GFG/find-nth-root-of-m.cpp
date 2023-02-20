//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int NthRoot(int n, int m){
	   // if (x == 0 || x == 1)
    //     return x;

    //  int start = 1, end = x;
    // while (start <= end) {
    //      int mid = (start + end) / 2;
    //      int sqr = pow(mid,n);
    //     if (sqr == x)
    //         return mid;
    //   else if (sqr < x) {
    //         start = mid + 1;
    //     }
    //     else 
    //         end = mid - 1;
    // }
    // return -1;
    if(m==0) return 0;
	    if(m==1) return 1;
	    
	    int l=1;
	    int r=m/n;
	    
	    while(l<=r){
	        int mid=(l+r)/2;
	        int mul=1;
	        if(pow(mid,n)==m){
	            return mid;
	        }
	        else if(pow(mid,n)>m){
	            r=mid-1;
	        }
	        else if(pow(mid,n)<m){
	            l=mid+1;
	        }
	    }
	    return -1;
	}  
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.NthRoot(n, m);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends