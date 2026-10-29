// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) 
//     {
//         if(s == "")
//         {
//             return 0;
//         }

//         unordered_map<char,int> entity;

//         int max_e = 1;
//         int st = 0;

//         for(int i = 0; i < s.length(); i++)
//         {
//             if(entity.find(s[i]) == entity.end())
//             {
//                 entity[s[i]] = i;
//             }
//             else
//             {
//                 int temp = entity[s[i]];
//                 for(int z = st; z <= temp; z++)
//                 {
//                     entity.erase(s[z]);
//                 }
//                 entity[s[i]] = i;
//                 st = temp + 1;
//             }
//             max_e = max(max_e, i - st + 1);
//         }
//         return max_e;
//     }
// };
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        vector<int> last(256, -1);   // last[c] = last index where char c was seen
        int st = 0;                  // left edge of the window
        int best = 0;

        for (int i = 0; i < (int)s.size(); i++)
        {
            unsigned char c = s[i];

            if (last[c] >= st)       // seen inside the current window
                st = last[c] + 1;    // jump the left edge past it

            last[c] = i;
            best = max(best, i - st + 1);
        }
        return best;
    }
};