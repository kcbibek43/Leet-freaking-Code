class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        vector<vector<int>> a;
        for(int i=0;i<mat.size();i++){
            int m = 0;
         for(int j=0;j<mat[i].size();j++){
             m+=mat[i][j];
         }
           a.push_back({m,i});
        }
        sort(a.begin(),a.end());
    vector<int> ans;
        for(int i =0;i<k;i++){
         ans.push_back(a[i][1]);
        }
//     for(auto i=a.begin();i!=a.end();i++){
//         ans.push_back(i->second);
// }
    return ans;
        //   vector<vector<int>> temp;
        // for(int i = 0;i<mat.size();i++){
        //     int sum = 0;
        //     for(int j = 0;j<mat[i].size();j++){
        //         sum+=mat[i][j];
        //     }
        //     temp.push_back({sum,i});
        // }
        // sort(temp.begin(),temp.end());
        // vector<int> ans;
        // for(int i = 0;i<k;i++){
        //     ans.push_back(temp[i][1]);
        // }
        // return ans;
    }
};