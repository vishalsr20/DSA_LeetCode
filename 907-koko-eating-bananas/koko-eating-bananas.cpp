class Solution {
public:
    long long solve(vector<int>& piles, int n, int speed){
        long long  h = 0;
        for(int i=0; i<n; i++){
            h = h + (piles[i] / speed);
            if(piles[i] % speed != 0){
                h++;
            }
        }
    return  h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low  = 1;
        int high = INT_MIN;
        for(int i=0; i<n; i++){
            high = max(high,piles[i]);
        }
        int result = -1;

        while(low <= high){
            int mid = low + (high - low) /2;
            long long hours = solve(piles,n,mid);
            if(hours > h){
                low = mid+1;
            }else{
                result = mid;
                high = mid-1;
            }
        }
     return result;   
    }
};