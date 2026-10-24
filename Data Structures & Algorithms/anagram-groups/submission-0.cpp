class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        vector<vector<string>> result;

        unordered_map<string, vector<string>> groups;
        for(const string& s : strs)
        {
            string key = s;
            sort(key.begin(), key.end());
            groups[key].push_back(s);
        }

        for(auto& pair : groups)
        {
            result.push_back(std::move(pair.second));
        }
        return result;
    }
};
