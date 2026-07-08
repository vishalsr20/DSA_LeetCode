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
    void createMapping(map<int,int>&mp, vector<int>&inorder){
        for(int i=0; i<inorder.size(); i++){
            int ele = inorder[i];
            mp[ele] = i;
        }
    }
    TreeNode* createBT(vector<int>& inorder, vector<int>& postorder,map<int,int>&mp,
    int inStart, int inEnd, int poStart, int& poEnd){
        if(inStart > inEnd || poEnd < 0 ){
            return NULL;
        }
        int ele = postorder[poEnd];
        int position = mp[ele];
        poEnd--;
        TreeNode* root = new TreeNode(ele);
        root->right =createBT(inorder,postorder,mp,position+1,inEnd,poStart,poEnd);
        root->left = createBT(inorder,postorder,mp,inStart,position-1,poStart,poEnd);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int>mp;
        createMapping(mp,inorder);
        int inStart = 0;
        int inEnd = inorder.size()-1;
        int poStart = 0;
        int poEnd = postorder.size()-1;
        TreeNode* root = createBT(inorder,postorder,mp,inStart,inEnd,poStart,poEnd);
        return root;
        
    }
};