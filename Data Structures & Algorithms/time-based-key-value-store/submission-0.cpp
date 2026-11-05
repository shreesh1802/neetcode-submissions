#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class TimeMap {
private:
    
    unordered_map<string, vector<pair<int, string>>> store;

public:
    TimeMap()
    {
    }

    void set(string key, string value, int timestamp)
    {
        store[key].push_back({timestamp, value});   
    }

    string get(string key, int timestamp)
    {
        auto it = store.find(key);
        if (it == store.end()) return "";           
        vector<pair<int, string>>& v = it->second;

        int lo = 0, hi = (int)v.size() - 1;
        int ans = -1;                              

        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;

            if (v[mid].first <= timestamp)
            {
                ans = mid;                         
                lo = mid + 1;
            }
            else
            {
                hi = mid - 1;                      
            }
        }

        return (ans == -1) ? "" : v[ans].second;
    }
};