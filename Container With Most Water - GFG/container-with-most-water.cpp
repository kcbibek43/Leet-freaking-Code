//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;
// int maxArea(int A[], int len);

// } Driver Code Ends
//User function template for C++

long long maxArea(long long height[], int len){   
    int i = 0;
    int j = len-1;
    long long ans = (len-1)*min(height[0],height[j]);
    while(i<j){
         ans = max(ans,min(height[i],height[j])*(j-i));
         if(height[i]<height[j]){
             i++;
         }
         else{
             j--;
         }
    }
    return ans;
}

//{ Driver Code Starts.

// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
    {
        int n;
        cin>>n;
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cout<<maxArea(arr,n)<<endl;
    }
return 0;
}

// } Driver Code Ends