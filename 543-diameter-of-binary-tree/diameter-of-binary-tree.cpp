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
    int solve(TreeNode* root){
        if(!root){
            return 0;
        }
        int left = 1+solve(root->left);
        int right = 1+solve(root->right);
        
        return max(left,right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root){
            return 0;
        }
        int ans1 = diameterOfBinaryTree(root->left);
        int ans2 = diameterOfBinaryTree(root->right);
        int sum = solve(root->left) +  solve(root->right);

        return max({ans1,ans2,sum});
        
    }
};