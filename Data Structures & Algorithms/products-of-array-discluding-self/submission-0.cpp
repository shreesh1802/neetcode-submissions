class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        int n = nums.size() ;
        vector<int> res_left(n,1);
        for(int i = 1; i < n; i++)
        {
            res_left[i] = res_left[i-1]*nums[i-1];
        }

        vector<int> res_right(n,1);
        for(int i = n-2; i >= 0; i--)
        {
            res_right[i] = res_right[i+1]*nums[i+1];
        }
        
        vector<int> result(n);
        for(int i = 0; i < n; i++)
        {
            result[i] = res_right[i]*res_left[i]; 
        }
        return result;
    }
};
