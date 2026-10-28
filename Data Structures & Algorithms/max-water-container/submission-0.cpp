class Solution {
public:
    int maxArea(vector<int>& heights) 
    {
        int p1 = 0;
        int p2 = heights.size() - 1;
        int area = 0;
        int calc;
        while(p1 < p2)
        {
            calc = min(heights[p1],heights[p2])*(p2-p1);
            area = max(area,calc);

            if(heights[p1] < heights[p2])
            {
                p1++;
            }
            else
            {
                p2--;
            }
        }
        return area;
    }
};    
      

