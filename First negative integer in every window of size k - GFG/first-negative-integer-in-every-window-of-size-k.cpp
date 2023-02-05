//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {

vector<long long> ans;
 int x = 0;
 int y = 0;
 queue<int> q;
 for(int i=0;i<K;i++){
     if(A[i]<0) q.push(A[i]);
 }
 for(int i=K;i<N;i++){
     if(!q.empty()){
         if(A[i-K]==q.front()){
             ans.push_back(q.front());
             q.pop();
         }
         else{
              ans.push_back(q.front());
         }
     }
     else{
         ans.push_back(0);
     }
     if(A[i]<0) q.push(A[i]);
 }
 bool falg = true;
 for(int i=N-K;i<N;i++){
     if(A[i]<0){
         falg = false;
         ans.push_back(A[i]);
         break;
     }
 }
 if(falg) ans.push_back(0); 
 return ans;
 }