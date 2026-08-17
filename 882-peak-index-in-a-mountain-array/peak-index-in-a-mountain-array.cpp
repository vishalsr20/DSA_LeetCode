class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int left = 0;
        int right = arr.size()-1;
        int result = -1;
        while(left <= right){
            int mid = left + (right - left)/2;
            if(arr[mid] < arr[mid+1]){
                left = mid+1;
            }else{
                result = mid;
                right = mid-1;
            }
            
        }
        return result;
    }
};