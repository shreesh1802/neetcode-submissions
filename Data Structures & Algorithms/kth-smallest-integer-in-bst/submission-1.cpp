class Solution {
public:
    int kthSmallest(TreeNode* root, int k)
    {
        stack<TreeNode*> stck;
        TreeNode* curr = root;

        while (curr != nullptr || !stck.empty())
        {
         
            while (curr != nullptr)
            {
                stck.push(curr);
                curr = curr->left;
            }

           
            curr = stck.top();
            stck.pop();

            k--;
            if (k == 0) return curr->val;

            
            curr = curr->right;
        }

        return -1; 
    }
};