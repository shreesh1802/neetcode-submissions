class Solution {
public:
    int findMin(vector<int> &nums) 
    {
        int left = 0; 
        int right = nums.size() - 1;
        int mid;
        while(left <= right)
        {
            mid = (left + right)/2;

            if(nums[left] <= nums[right])
            {
                return nums[left];
            }
            else if(nums[mid] >= nums[right])
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }    
        return nums[0];
    }
};
