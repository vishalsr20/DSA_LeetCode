/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool solve(TreeNode* root, TreeNode* node, vector<TreeNode*>&st){
        if(!root){
            return false;
        }
        st.push_back(root);
        if(root == node){
            return true;
        }
        if(solve(root->left,node,st)) return true;
        if(solve(root->right,node,st)) return true;
        st.pop_back();
        return false;;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root){
            return root;
        }
        vector<TreeNode*>P;
        vector<TreeNode*>Q;
        solve(root,p,P);
        solve(root,q,Q);
         reverse(P.begin(),P.end());
        reverse(Q.begin(),Q.end());

        for(auto it:P){
            TreeNode* temp = it;
            for(auto ch:Q){
                if(temp == ch){
                    return temp;
                }
            }
        }
        return NULL;
    }
};