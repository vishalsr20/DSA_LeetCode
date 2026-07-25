class Solution {
public:
    int maxProduct(int n) {
        vector<int>num;
        while(n != 0){
            num.push_back(n%10);
            n/=10;
        }
        int maxPro = 0;
        for(auto it:num){
            cout<<it<<endl;
        }
        n = num.size();
        for(int i=0; i<n; i++){
            int temp = 0;
            for(int j=i+1; j<n; j++){
               temp = max(temp,num[i]*num[j]);
            }
            maxPro = max(maxPro,temp);
        }
        return maxPro;
    }
};