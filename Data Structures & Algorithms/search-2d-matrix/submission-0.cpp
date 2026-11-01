class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        vector<int> res;

         for(int i = 0; i < matrix.size(); i++)
         {
            for(int j = 0; j < matrix[0].size(); j++)
            {
                res.push_back(matrix[i][j]);
            }
         } 

         int left = 0;
         int right = res.size() - 1;

         while(left <= right)
         {
            int mid = (left + right)/2;
            if(res[mid] == target)
            {
                return true;
            }
            else if(target < res[mid])
            {
                right = mid -1 ;
            }
            else
            {
                left = mid + 1;
            }
         }  
         return false;
    }
};
