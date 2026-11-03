class Solution {
public:
    int findDuplicate(vector<int>& nums) 
    {
        int p1 = 0;
        int p2 = 1;

        while(p1 <= p2 && p2 <= nums.size()-1 && p1 <= nums.size()-1)
        {
            if(nums[p1] == nums[p2])
            {
                return nums[p1];
                break;
            }
            if(p2 == nums.size()-1)
            {
                p1++;
                p2 = p1;
            }
            p2++;
        }
        return -1;
    }
};
