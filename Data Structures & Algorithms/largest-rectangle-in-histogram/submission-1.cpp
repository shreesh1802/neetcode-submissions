class Solution {
public:
    int largestRectangleArea(vector<int>& heights)
    {
        int n = heights.size();
        vector<int> prefix(n), suffix(n);

        for(int i = 0; i < n; i++)
        {
            int j = i - 1;
            while(j >= 0 && heights[j] >= heights[i])
                j = prefix[j];                
            prefix[i] = j;                     
        }

        for(int i = n - 1; i >= 0; i--)
        {
            int j = i + 1;
            while(j < n && heights[j] >= heights[i])
                j = suffix[j];
            suffix[i] = j;                   
        }

        int area = 0;
        for(int i = 0; i < n; i++)
        {
            area = max(area, heights[i] * (suffix[i] - prefix[i] - 1));
        }
        return area;
    }
};