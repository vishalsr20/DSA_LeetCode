class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>sum;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0; i<n-2; i++){
            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            }
            int j=i+1; 
            int k = n-1;

            while(j < k){
                int checkSum = nums[i] + nums[j] + nums[k];
                if( checkSum == 0){
                    sum.push_back({nums[i],nums[j],nums[k]});
                     while(j < k && nums[j] == nums[j+1]){
                    j++;
                    }
                    while(j < k && nums[k] == nums[k-1]){
                        k--;
                    }

                }
                if(checkSum < 0){
                    j++;
                }else{
                    k--;
                }
               
            }
        }
        return sum;
    }
};