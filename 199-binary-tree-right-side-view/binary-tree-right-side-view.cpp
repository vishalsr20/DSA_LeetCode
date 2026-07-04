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
    vector<int> rightSideView(TreeNode* root) {
        if(root == NULL){
            return {};
        }
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        vector<int>ans;

        while(!q.empty()){
             
            int value;
             while(q.front() != NULL){
                TreeNode* temp = q.front();
                value = temp->val;
                if(temp->left != NULL){
                q.push(temp->left);
                }
                if(temp->right != NULL){
                q.push(temp->right);
                }
                q.pop();
            
             }
             q.pop();

              if(!q.empty()){
                q.push(NULL);
              }
                ans.push_back(value);

        }
        return ans;
    }
};