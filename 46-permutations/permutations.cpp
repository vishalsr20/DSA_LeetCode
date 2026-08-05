class Solution {
public:
    void solve(vector<int>nums, vector<vector<int>>&ans, int start){
        int n = nums.size();
        if(start >= n){
           ans.push_back(nums);
            return ;
        }
        
        for(int i=start; i<n; i++){
            swap(nums[start],nums[i]);
            solve(nums,ans,start+1);
            swap(nums[start],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        solve(nums,ans,0);
        return ans;
        
    }
};