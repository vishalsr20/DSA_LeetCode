class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.length();
        unordered_map<char,int>mp;
        for(int i=0; i<n; i++){
            mp[s[i]]++;
        }
        for(int i=0; i<n; i++){
            char ch = s[i];
            if(mp.find(ch) != mp.end()){
                if(mp[ch] == 1){
                    return i;
                }
            }
        }
        return -1;
        
    }
};