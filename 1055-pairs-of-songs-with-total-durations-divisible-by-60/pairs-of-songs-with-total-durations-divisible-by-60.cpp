class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int,int>mp;
        int n = time.size();
        int count = 0;
        for(int i=0; i<n; i++){
            int rem = (time[i] % 60);
            int need = (60 - rem) % 60;
            if(mp.find(need) != mp.end()){
                count+=mp[need];
            }
            mp[rem]++;
        }
        return count;
        
    }
};