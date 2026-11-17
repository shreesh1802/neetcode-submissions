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
    int countNodes(TreeNode* root,int init)
    {
        if(root == nullptr) return 0;

        int count = 0;
        if(root->val >= init)
        {
            count = 1;
            init = root->val;
        }

        count += countNodes(root->left,init);
        count += countNodes(root->right,init);

        return count;
    }
    int goodNodes(TreeNode* root) 
    {
       return countNodes(root,root->val);
    }
};
