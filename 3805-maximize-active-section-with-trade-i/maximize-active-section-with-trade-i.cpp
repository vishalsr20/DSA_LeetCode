class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int ones = 0;
        for(auto ch:s){
            if(ch == '1'){
                ones++;
            }
        }
        s.insert(s.begin(),'1');
        s.push_back('1');

        vector<string>groups;
        string curr = "";
        curr+=s[0];
        for(int i=1; i<s.size(); i++ ){
            if(s[i] == s[i-1]){
                curr+=s[i];
            }else{
                groups.push_back(curr);
                curr.clear();
                curr+=s[i];
            }
        }
        groups.push_back(curr);

        int gain = 0;
        for(int i=1; i<groups.size()-1; i++){

            if(groups[i-1][0] == '0' && groups[i][0] == '1' && groups[i+1][0] == '0'){
                gain = max(gain,(int) groups[i-1].size() + (int)groups[i+1].size());
            }
        }
        return ones+gain;
    }
};