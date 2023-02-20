//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    bool check(int A[],int M,int N,int m){
    int s = 0;
    int cnt = 1;
        for(int i=0;i<N;i++){
            s += A[i];
            if(A[i]>m)  return false;
            if(s>m){
            s = A[i];
            cnt++;
            }
        }
 return cnt<=M;
    }
    int findPages(int A[], int N, int M) 
    {
        if(M>N){
            return -1;
        }
        if(M==N){
            int mx = -1;
            for(int i=0;i<N;i++){
                mx = max(mx,A[i]);
            }
            return mx;
        }
        int l = INT_MAX;
        int h = 0;
        for(int i=0;i<N;i++){
            l = min(l,A[i]);
            h += A[i];
        }
     int ans = INT_MAX;
     while(l<=h){
         int m = (l+h)/2;
         if(check(A,M,N,m)){
             ans = m;
             h = m - 1 ;
         }
         else{
             l = m + 1;
         }
     }
     if(ans == INT_MAX) return -1;
     return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends