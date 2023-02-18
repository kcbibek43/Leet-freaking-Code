//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int countSmaller(vector<int> A,int mid){
        int l = 0;
        int h = A.size()-1;
        while(l<h){
            int m = (l+h)/2;
            if(A[m]<=mid){
                l = m + 1;
            }
            else{
                h = m + 1;
            }
        }
        return l;
    }
    int median(vector<vector<int>> &mat, int R, int C){
        int low = 1e9;
        int high = -1e9;
        for(int i=0;i<R;i++){
            low = min(low,mat[i][0]);
            high = max(high,mat[i][C-1]);
        }
        int x = (R*C+1)/2;
        while(low<high){
            int mid = (low+high)/2;
            int cnt = 0;
            for(int i=0;i<R;i++){
                cnt += upper_bound(mat[i].begin(),mat[i].end(),mid) - mat[i].begin();
            }
            if(cnt < x )  low = mid + 1;
            else high = mid;
        }
        return low;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        int ans=-1;
        ans=obj.median(matrix, r, c);
        cout<<ans<<"\n";        
    }
    return 0;
}
// } Driver Code Ends