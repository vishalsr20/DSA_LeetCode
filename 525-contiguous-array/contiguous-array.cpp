class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int>mp;
        int result = INT_MIN;
        int zero = 0;
        int one = 0;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(nums[i] == 0){
                zero++;
            }else{
                one++;
            }
            int diff = zero - one;
            if(diff == 0){
                result = max(result , i+1);
            }else{
            if(mp.find(diff) != mp.end()){
                result = max(result,i - mp[diff] );
            }else{
                mp[diff] = i;
            }
            }
        }
       return result == INT_MIN ? 0 : result; 
    }
};