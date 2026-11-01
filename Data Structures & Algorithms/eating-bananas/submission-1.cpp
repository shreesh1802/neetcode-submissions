#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h)
    {
        int lo = 1;
        int hi = *max_element(piles.begin(), piles.end());   
        int ans = hi;

        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;

            
            long long hours = 0;
            for (int p : piles)
                hours += (p + (long long)mid - 1) / mid;     

            if (hours <= h)
            {
                ans = mid;        
                hi = mid - 1;
            }
            else
            {
                lo = mid + 1;    
            }
        }
        return ans;
    }
};