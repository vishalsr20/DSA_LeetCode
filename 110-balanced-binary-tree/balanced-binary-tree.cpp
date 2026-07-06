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
        int left =1+ solve(root->left);
        int right = 1 + solve(root->right);

        return max(left,right);
    }
    bool isBalanced(TreeNode* root) {
        if(!root){
            return true;
        }
        int left= solve(root->left);
        int right = solve(root->right);
        int bal = abs(right -left);
        bool diff = (bal <= 1);
        bool leftAns =  isBalanced(root->left);
        bool rightAns = isBalanced(root->right);
        if(diff && leftAns && rightAns){
            return true;
        }
        return false;
        
    }
};