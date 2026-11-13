class Solution {
public:
    bool same(TreeNode* a, TreeNode* b)
    {
        if (a == nullptr && b == nullptr) return true;    
        if (a == nullptr || b == nullptr) return false;    
        if (a->val != b->val) return false;

        return same(a->left, b->left) && same(a->right, b->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot)
    {
        if (subRoot == nullptr) return true;     
        if (root == nullptr) return false;       
        if (same(root, subRoot)) return true;   

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};