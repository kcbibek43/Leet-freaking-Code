class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
               unordered_map<string, vector<string>> hash;
        for (auto &path: paths) {
            stringstream ss(path);
            string p, file;
            ss >> p;
            while (ss >> file) {
                auto x = file.find("("), y = file.find(")");
                string name = file.substr(0, x), cont = file.substr(x + 1, y - x - 1);
                string full_path = p + "/" + name;
                hash[cont].emplace_back(move(full_path));
            }
        }
        vector<vector<string>> ans;
        for (auto &[k, v] : hash)
            if (v.size() > 1) ans.emplace_back(move(v));
        return ans;
    }
};