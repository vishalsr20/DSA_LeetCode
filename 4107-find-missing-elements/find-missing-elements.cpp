class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        map<int,int>mp;
        int n = nums.size();
        int start = nums[0];
        vector<int>ans;
          for (int i = 1; i < n; i++) {
            while (start + 1 < nums[i]) {
                ans.push_back(start + 1);
                start++;
            }
            start = nums[i];
        }
    return ans;    
    }
};