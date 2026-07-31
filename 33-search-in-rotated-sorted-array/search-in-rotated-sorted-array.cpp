class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int result = -1;
        int low = 0;
        int high = n-1;

        while(low <= high){
            int mid = low + (high - low) / 2;
            if(nums[mid] > nums[n-1]){
                low = mid+1;
            }else{
                result = mid;
                high = mid-1;
            }
        }
        int mini = result;
        low = 0;
        high = mini;
        
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(nums[mid] == target){
                return mid;
            }

            if(nums[mid] < target){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        low = mini;
        high = n-1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(nums[mid] == target){
                return mid;
            }

            if(nums[mid] < target){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }

        return -1;
        
    }
};