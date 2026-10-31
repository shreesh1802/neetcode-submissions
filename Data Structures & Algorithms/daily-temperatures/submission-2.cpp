class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures)
    {
        int n = temperatures.size();
        vector<int> res(n, 0);         
        stack<int> stck;                

        for (int i = 0; i < n; i++)
        {
            
            while (!stck.empty() && temperatures[i] > temperatures[stck.top()])
            {
                int idx = stck.top();
                stck.pop();
                res[idx] = i - idx;
            }
            stck.push(i);               
        }
        return res;                     
    }
};