class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>mp;

        for(int i=0; i<nums.size(); i++){
            int check = target;
            check = (target - nums[i]);
            if(mp.find(check) != mp.end()){
                return {mp[check] , i};
            }
            mp[nums[i]] = i ;
        }
      
        return {};
    }
};