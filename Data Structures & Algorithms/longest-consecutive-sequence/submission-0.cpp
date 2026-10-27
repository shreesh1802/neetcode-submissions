class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        unordered_set<int> s;

        for(int x : nums)
        {
            s.insert(x);
        }
        
        int best = 0;

        for(int num : s)
        {
            if(s.count(num-1)) continue;

            int cur = num;
            int len = 1;
            while(s.count(cur + 1))
            {
                cur++;
                len++;
            }
            best = max(best,len);
        }
        return best;
    }
};
