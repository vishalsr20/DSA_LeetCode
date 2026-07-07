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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(!root){
            return ans;
        }
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        bool check = false;
        while(!q.empty()){
            vector<int>t;
            while(!q.empty() && q.front() != NULL ){
                TreeNode* temp = q.front();
                t.push_back(temp->val);
                
                if(temp->left != NULL){
                    q.push(temp->left);
                }
                if(temp->right != NULL){
                    q.push(temp->right);
                }
                q.pop();
            }
            q.pop();
            
            if(check == true){
                reverse(t.begin(),t.end());
               
            }
            ans.push_back(t);
            check=!check;
            
            if(!q.empty()){
                q.push(NULL);
            }
            
        }
        return ans;
    }
};