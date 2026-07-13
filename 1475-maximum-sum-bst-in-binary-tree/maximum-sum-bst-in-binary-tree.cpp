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
    struct Info{
        bool isBST;
        int minNode;
        int maxNode;
        int sum;
    };
    int ans = 0;
    
    Info solve(TreeNode* root){
        if(!root){
            return {true, INT_MAX, INT_MIN, 0};
        }

        Info left = solve(root->left);
        Info right = solve(root->right);
        if (left.isBST &&
            right.isBST &&
            left.maxNode < root->val &&
            root->val < right.minNode) {

            int currSum = left.sum + right.sum + root->val;

            ans = max(ans, currSum);

            return {
                true,
                min(root->val, left.minNode),
                max(root->val, right.maxNode),
                currSum
            };
        }
        return {false, INT_MIN, INT_MAX, 0};

    }
    int maxSumBST(TreeNode* root) {
        if(!root){
            return 0;
        }
        solve(root);
        return ans;
        
    }
};