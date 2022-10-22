//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string beginWord, string endWord, vector<string>& wordList) {
              queue<pair<string , int>> q;
       q.push({beginWord,1});
       unordered_set<string> st(wordList.begin(),wordList.end());
       st.erase(beginWord);
       while(!q.empty()){
          string s1 = q.front().first;
          int step = q.front().second;
          q.pop();
          if(s1 == endWord){
              return step;
          }
          for(int i=0;i<s1.size();i++){
              char c1 = s1[i];
          for(char ch = 'a' ;ch<='z';ch++){
              s1[i]=ch;
              if(st.count(s1)>0){
                  q.push({s1,step+1});
                  st.erase(s1);
              }
          }
          s1[i] = c1;
          }
       }
return 0;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends