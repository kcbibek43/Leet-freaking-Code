//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
 queue<pair<int,int>> q;
        if(image[sr][sc]==color) return image;
        int c=image[sr][sc];
        image[sr][sc]=color;
        q.push({sr,sc});
        while(!q.empty()){
            int f=q.front().first;
            int s=q.front().second;
            q.pop();
            if(f-1 >= 0 and image[f-1][s]==c){
                q.push({f-1,s});
                image[f-1][s]=color;
            } 
            if(s-1 >= 0 and image[f][s-1]==c){
                q.push({f,s-1});
                image[f][s-1]=color;
            } 
            if(f+1 < image.size()  and image[f+1][s]==c){
                q.push({f+1,s});
                image[f+1][s]=color;
            } 
            if(s+1 < image[0].size()  and image[f][s+1]==c){
                q.push({f,s+1});
                image[f][s+1]=color;
            }
        }
        return image;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends