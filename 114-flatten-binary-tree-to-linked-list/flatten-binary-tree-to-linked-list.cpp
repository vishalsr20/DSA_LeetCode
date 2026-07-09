class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root)
            return;
        flatten(root->left);
        flatten(root->right);
        TreeNode* rightSubtree = root->right;
        root->right = root->left;
        root->left = NULL;

        
        TreeNode* curr = root;
        while (curr->right) {
            curr = curr->right;
        }

        
        curr->right = rightSubtree;
    }
};