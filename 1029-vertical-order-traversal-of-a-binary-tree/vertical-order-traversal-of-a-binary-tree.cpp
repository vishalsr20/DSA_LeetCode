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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
        vector<tuple<int,int,int>>mp;
        queue<pair<TreeNode*, pair<int,int>>> q;
        
        q.push({root,{0,0}});
        while(!q.empty()){
            auto temp = q.front();
            q.pop();

            int row = temp.second.first;
            int col = temp.second.second;
            TreeNode* node = temp.first;
           
            mp.push_back({col,row,node->val});
            if(node->left != NULL){
                q.push({node->left,{row+1,col-1}});
            }
            if(node->right != NULL){
                q.push({node->right,{row+1,col+1}});
            }
           
        }
         sort(mp.begin(),mp.end());
        int i = 0;
        int n = mp.size();
        while(i < n) {
        vector<int> temp;
        int col = get<0>(mp[i]);

        while(i < n && get<0>(mp[i]) == col) {
            temp.push_back(get<2>(mp[i]));
            i++;
        }
        ans.push_back(temp);
        }
        
        return ans;
    }
};