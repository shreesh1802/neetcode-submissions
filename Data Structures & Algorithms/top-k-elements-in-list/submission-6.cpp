class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;

        
        for (int num : nums) {
            count[num]++;
        }

        
        vector<pair<int, int>> frequencies;

        for (auto& [num, freq] : count) {
            frequencies.push_back({freq, num});
        }

      
        sort(frequencies.begin(), frequencies.end(),
             [](const pair<int, int>& a, const pair<int, int>& b) 
             {
                 return a.first > b.first;
             });

        vector<int> result;

        for (int i = 0; i < k; i++) {
            result.push_back(frequencies[i].second);
        }

        return result;
    }
};