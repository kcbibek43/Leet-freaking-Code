class Solution {
public:
    bool canCross(vector<int>& stones) {
        map<int,set<int>>  m;
        for(int i=0;i<stones.size();i++){
      m[stones[i]]={};  
        }
        m[stones[0]].insert(1);
        for(int i=0;i<stones.size();i++){
     int cur = stones[i];
            set<int> jump = m[cur];
            for(auto j : jump){
                int p = j+cur;
                if(p==stones[stones.size()-1]){
                    return true;
                }
                else if(m.find(p) != m.end()){
                    if(j-1>0){
                        m[p].insert(j-1);
                    }
                    m[p].insert(j);
                    m[p].insert(j+1);
                }
            }
        }
        return false;
    }
};