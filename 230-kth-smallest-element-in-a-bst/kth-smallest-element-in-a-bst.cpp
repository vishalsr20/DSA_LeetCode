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
    void solve(TreeNode* root, int& k, priority_queue<int>&pq){
        if(!root){
            return;
        }
        if(pq.size() < k){
            pq.push(root->val);
        }else if(pq.top() > root->val){
            pq.pop();
            pq.push(root->val);
        }
        solve(root->left,k,pq);
        solve(root->right,k,pq);
        return;
    }
    int kthSmallest(TreeNode* root, int k) {
        priority_queue<int>pq;
        solve(root,k,pq);
        return pq.top();
    }
};