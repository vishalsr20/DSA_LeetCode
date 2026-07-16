class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<long long>pref(n);
        int maxi = INT_MIN;
        for(int i=0; i<n; i++){
            maxi = max(nums[i],maxi);
            pref[i] = gcd(nums[i],maxi);
        }

        sort(pref.begin(),pref.end());
        long long sum = 0;
        int start = 0;
        int end = n - 1;
        while(start < end){
            if(pref[start] <= pref[end]){
                sum+=gcd(pref[start],pref[end]);
              
               
            }
             start++;
             end--;
        }
        return sum;
    }
};