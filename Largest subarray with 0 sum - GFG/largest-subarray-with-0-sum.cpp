//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n){   
    map<int,int> pref;
    int sum = 0;
    int mx = 0;
    for(int i=0;i<A.size();i++){
        sum+=A[i];
        if(sum == 0)  mx = i+1;
        else{
            if(pref.find(sum) != pref.end()){
                mx = max(mx,i-pref[sum]);
            }
            else{
                pref[sum] = i;
            }
        }
    }
    return mx;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends