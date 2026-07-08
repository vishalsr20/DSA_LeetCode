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
    int maxSum = INT_MIN;
    int  sum(TreeNode* root){
        if(!root){
            return 0;
        }
        int left =root->val + sum(root->left);
        int right = root->val+sum(root->right);
        
        return max({0,left,right});
    }
    int maxPathSum(TreeNode* root) {
        if(!root){
            return 0;
        }
        
        int curr = root->val;
        int leftGain = max(0,sum(root->left));
        int rightGain = max(0,sum(root->right));
        cout<<leftGain<<" "<<rightGain<<endl;
        int currVal = curr + leftGain + rightGain;
        maxSum = max(maxSum,currVal);
        maxPathSum(root->left);
        maxPathSum(root->right);
        return maxSum;
    }
};