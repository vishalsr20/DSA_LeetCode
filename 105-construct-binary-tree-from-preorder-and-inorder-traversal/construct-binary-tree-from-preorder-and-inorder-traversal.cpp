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
    void createMapping(map<int,int>&mp,vector<int>&inorder){
        for(int i=0; i<inorder.size(); i++){
            mp[inorder[i]] = i;
        }
        return;
    }
    TreeNode* constructBT(map<int,int>&mp,vector<int>&inorder, vector<int>&preorder,int& preIndex, 
    int preSize,int inIndex, int inSize ){
        if(preIndex >= preSize || inIndex > inSize){
            return NULL;
        }

        int ele = preorder[preIndex];
        preIndex++;
        TreeNode* root = new TreeNode(ele);
        int position = mp[ele];
        root->left = constructBT(mp,inorder,preorder,preIndex,preSize,inIndex,position-1);
        root->right = constructBT(mp,inorder,preorder,preIndex,preSize,position+1,inSize);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int>mp;
        createMapping(mp,inorder);
        int preIndex = 0;
        int preSize = preorder.size();
        int inIndex = 0;
        int inSize = inorder.size();
        TreeNode* root = constructBT(mp,inorder,preorder,preIndex,preSize,inIndex,inSize);
        return root;
        
    }
};