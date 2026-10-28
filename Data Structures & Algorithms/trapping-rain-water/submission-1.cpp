class Solution {
public:
    int trap(vector<int>& height) 
    {
        vector<int>prefix;
        vector<int>suffix;
        int pre = 0; int suf = 0;int water = 0;
        for(int i = 0; i < height.size(); i++)
        {
            pre = max(pre,height[i]);
            prefix.push_back(pre);
        }

        for(int i = height.size()-1; i >= 0; i--)
        {
            suf = max(suf,height[i]);
            suffix.push_back(suf);
        }
        reverse(suffix.begin(), suffix.end());

        for(int i = 0 ; i < height.size(); i++)
        {
            water += min(prefix[i], suffix[i]) - height[i];
        }
        return water;          
    }
};
