class Solution {
public:
    int best = 0;                                 

    int height(TreeNode* root)
    {
        if (root == nullptr) return 0;

        int diaL = height(root->left);
        int diaR = height(root->right);

        best = max(best, diaL + diaR);            

        return max(diaL, diaR) + 1;                
    }

    int diameterOfBinaryTree(TreeNode* root)
    {
        best = 0;
        height(root);
        return best;
    }
};