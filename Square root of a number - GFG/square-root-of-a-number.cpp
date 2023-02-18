//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

  

// } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution{
  public:
    long long int floorSqrt(long long int x) 
    {
    //      if(x == 1 ) return x;
    //  int l = 1;
    //  int h = x/2;
    //  int m = -1;
    //  int ans = -1;
    //  while(l<=h){
    //      m = (l+h)/2;
    //      if(m * m == x){
    //          return m;
    //      }
    //      if(m * m <= x){
    //          l = m + 1;
    //          ans = m;
    //      }
    //      else {
    //          h = m - 1;
    //      }
    //  }
    //  return ans; 
     if (x == 0 || x == 1)
        return x;

    long long int start = 1, end = x / 2, ans;
    while (start <= end) {
        long long int mid = (start + end) / 2;
        long long int sqr = mid * mid;
        if (sqr == x)
            return mid;
        if (sqr <= x) {
            start = mid + 1;
            ans = mid;
        }
        else 
            end = mid - 1;
    }
    return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		Solution obj;
		cout << obj.floorSqrt(n) << endl;
	}
    return 0;   
}

// } Driver Code Ends