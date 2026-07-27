class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxPro = 0;
        for(int i=0; i<n; i++){
            int temp = 0;
            for(int j=i+1; j<n; j++){
                int pro = (nums[i]-1) * (nums[j]-1);
                temp = max(temp,pro);
            }
            maxPro = max(maxPro,temp);
        }
        return maxPro;
    }
};