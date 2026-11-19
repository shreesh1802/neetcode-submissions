/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public: 

    int best = INT_MIN;
    int path(TreeNode* root)
    {
        if(root == nullptr)
        {
            return 0;
        }
        int curr = root->val;

        int left = max(0,path(root->left));
        int right = max(0,path(root->right));

        best = max(best, curr + left + right);

        return curr + max(left,right);
        
    }
    int maxPathSum(TreeNode* root) 
    {   
       best = INT_MIN;
       path(root);
       return best;
    }
};
