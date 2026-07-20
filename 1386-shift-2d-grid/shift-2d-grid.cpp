class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        
        int m = grid.size();
        int n = grid[0].size();
        vector<int>nums;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                nums.push_back(grid[i][j]);
            }
        }
        while(k--){
            int ele = nums.back();
            nums.pop_back();
            nums.insert(nums.begin(),ele);
        }

        int index = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                grid[i][j] = nums[index];
                index++;
            }
        }
        
        return grid;
    }
};