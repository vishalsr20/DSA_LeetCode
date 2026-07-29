class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int>have;
        for(auto it:text){
            have[it]++;
        }
        unordered_map<char,int>need{
            {'b',1},
            {'a',1},
            {'l',2},
            {'o',2},
            {'n',1}
        };
        int result = INT_MAX;

        for(auto it:need){
            auto first = it.first;
            auto second = it.second;
            int val = have[first];
            result = min(result,val/second);
        }

        return result;
    }
};