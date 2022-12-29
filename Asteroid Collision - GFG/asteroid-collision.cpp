//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> asteroidCollision(int N, vector<int> &asteroids) {
 vector<int> s; 
        for(int a : asteroids) {
            if(a > 0) s.push_back(a); 
            else if(a < 0) { 
                while(!s.empty() && s.back() > 0 && s.back() < abs(a)) s.pop_back();
                if(s.empty() || s.back() < 0) s.push_back(a); 
                else if(s.back() == abs(a)) s.pop_back(); 
        }
        }
        return s;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> asteroids(N);
        for (int i = 0; i < N; i++) cin >> asteroids[i];

        Solution obj;
        vector<int> ans = obj.asteroidCollision(N, asteroids);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends