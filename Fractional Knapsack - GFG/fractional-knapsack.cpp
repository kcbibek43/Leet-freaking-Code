//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        vector<pair<double,int>> vec;
        for(int i=0;i<n;i++){
            vec.push_back({arr[i].value/double(arr[i].weight),i});
        }
        sort(vec.begin(),vec.end());
        int i = 0;
        double ans = 0;
        for(i=n-1;i>=0;i--){
            int idx = vec[i].second;
            if(W>=arr[idx].weight){
                ans+=arr[idx].value;
                W-=arr[idx].weight;
            }
            else{
               double remain = W*vec[i].first;
               ans+=remain;
               break;
            }
        }
        
        return ans;
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends