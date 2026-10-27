#include <vector>
#include <unordered_set>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        vector<int> neg, pos;
        for (int x : nums)
        {
            if (x < 0) neg.push_back(x);
            else pos.push_back(x);
        }

        sort(neg.begin(), neg.end());
        sort(pos.begin(), pos.end());

        unordered_set<int> negSet(neg.begin(), neg.end());
        unordered_set<int> posSet(pos.begin(), pos.end());

        set<vector<int>> res;   

      
        for (int i = 0; i < (int)neg.size(); i++)
        {
            for (int j = i + 1; j < (int)neg.size(); j++)
            {
                int need = -(neg[i] + neg[j]);      
                if (posSet.count(need))
                    res.insert({neg[i], neg[j], need});
            }
        }

        
        for (int i = 0; i < (int)pos.size(); i++)
        {
            for (int j = i + 1; j < (int)pos.size(); j++)
            {
                int need = -(pos[i] + pos[j]);      
                if (negSet.count(need))
                    res.insert({need, pos[i], pos[j]});
            }
        }

        
        int zeros = 0;
        for (int x : pos) if (x == 0) zeros++;
        if (zeros >= 3) res.insert({0, 0, 0});

        return vector<vector<int>>(res.begin(), res.end());
    }
};