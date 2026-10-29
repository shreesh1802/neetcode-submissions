class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        if(s == "")
        {
            return 0;
        }

        unordered_map<char,int> entity;

        int max_e = 1;
        int st = 0;

        for(int i = 0; i < s.length(); i++)
        {
            if(entity.find(s[i]) == entity.end())
            {
                entity[s[i]] = i;
            }
            else
            {
                int temp = entity[s[i]];
                for(int z = st; z <= temp; z++)
                {
                    entity.erase(s[z]);
                }
                entity[s[i]] = i;
                st = temp + 1;
            }
            max_e = max(max_e, i - st + 1);
        }
        return max_e;
    }
};
