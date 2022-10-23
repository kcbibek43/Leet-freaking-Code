//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
          vector<vector<string>> s;
        unordered_set<string> st(wordList.begin(),wordList.end());
        int level = 0;
        queue<vector<string>> q;
        vector<string> thisWord;
        thisWord.push_back(beginWord);
        q.push({beginWord});
       while(!q.empty()){
            vector<string> qu = q.front();
      q.pop();
       if(qu.size()>level){
           level++;
           for(auto it : thisWord){
             st.erase(it);
           }
       }
       string word = qu.back();
       if(word == endWord){
           if(s.size()==0){
              s.push_back(qu);
           }
           else if(s[0].size()==qu.size()){
               s.push_back(qu);
           }
       }
       for(int i=0;i<word.size();i++){
           char org = word[i];
           for(char ch = 'a';ch<='z';ch++){
               word[i]=ch;
               if(st.count(word)>0){
                   qu.push_back(word);
                   q.push(qu);
                   qu.pop_back();
                   thisWord.push_back(word);
               }
           }
           word[i]=org;
       }
       }
        return s;
    }
};

//{ Driver Code Starts.

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for(string i: a)
        x += i;
    for(string i: b)
        y += i;
    
    return x<y;
}

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
		vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
		if(ans.size()==0)
		    cout<<-1<<endl;
		else
		{
		    sort(ans.begin(), ans.end(), comp);
            for(int i=0; i<ans.size(); i++)
            {
                for(int j=0; j<ans[i].size(); j++)
                {
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
		}
	}
	return 0;
}
// } Driver Code Ends