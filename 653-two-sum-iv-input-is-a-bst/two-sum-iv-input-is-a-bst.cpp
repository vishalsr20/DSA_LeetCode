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
    void solve(TreeNode* root, int k, unordered_map<int,int>&mp,bool& ans){
        if(!root){
            return ;
        }

        int val = k -  root->val;

        if(mp.find(val) != mp.end()){
            ans = true;
        }
        if(mp.find(val) == mp.end()){
            mp[root->val]++;
        }
        solve(root->left,k,mp,ans);
        solve(root->right,k,mp,ans);

        return;
    }
    bool findTarget(TreeNode* root, int k) {
        if(!root){
            return false;
        }
        bool ans = false;
        unordered_map<int,int>mp;
        solve(root,k,mp,ans);
        return ans;


    }
};