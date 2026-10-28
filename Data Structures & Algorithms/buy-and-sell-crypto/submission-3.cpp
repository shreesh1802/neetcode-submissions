// class Solution {
// public:
//     int maxProfit(vector<int>& prices) 
//     {
//         int p1 = 0;int p2 = prices.size();int idx = 0;int buy = 1 ;int sell = 1;

//         if(prices.size() == 1)
//         {
//             return 0;
//         }

//         if(prices.size() == 2)
//         {
//             if(prices[p1] < prices[p2-1])
//             {
//                 return prices[p2-1] - prices[p1];
//             }
//             else
//             {
//                 return 0;
//             }
//         }

//         while(p1 < p2)
//         {
//             if(prices[p1] <= prices[p2])
//             {
//                 buy = min(buy,prices[p1]);
//                 p2--;
//             }
//             if(prices[p1] < prices[idx])
//             {
//                 idx = p1;
//             }
//             p1++;
//         }

//         for(int i = idx + 1; i < prices.size(); i++)
//         {
//             sell = max(sell,prices[i]);
//         }

//         return sell - buy;
//     }
// };
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int buy = prices[0];      
        int profit = 0;           

        for (int i = 1; i < (int)prices.size(); i++)
        {
            buy = min(buy, prices[i]);             
            profit = max(profit, prices[i] - buy);   
        }
        return profit;
    }
};