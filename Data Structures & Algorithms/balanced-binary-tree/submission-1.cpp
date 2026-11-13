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
    int depthLeft(TreeNode* root)
    {
        if(root == nullptr)
        {
            return 0;
        }

        int depthl = depthLeft(root->left);
        int depthr = depthLeft(root->right);

        return max(depthl,depthr) + 1;
    }

    int depthRight(TreeNode* root)
    {
        if(root == nullptr)
        {
            return 0;
        }

        int depthL = depthRight(root->left);
        int depthR = depthRight(root->right);

        return max(depthL,depthR) + 1;
    }
    
    bool isBalanced(TreeNode* root) 
    {
        if(root == nullptr)
        {
            return true;
        }
        if(abs(depthLeft(root->left) - depthRight(root->right)) > 1)
        {
            return false;
        }
        return isBalanced(root->left) && isBalanced(root->right);
    }
};
