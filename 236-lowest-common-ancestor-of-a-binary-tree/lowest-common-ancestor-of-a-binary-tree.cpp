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
         
        int i= 0;
        TreeNode* temp = NULL;
        while(i < P.size() && i < Q.size()){
            if(P[i] == Q[i]){
                temp = P[i];
            }
            i++;
        }
        return temp;
    }
};