class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        stack<pair<int,int>>st;
        int n = arr.size();
        for(int i=0; i<n; i++){
            if(st.empty()){
                st.push({arr[i],i});
            }else{
                if(arr[i] >= st.top().first){
                    st.push({arr[i],i});
                }
            }

        }

        return st.top().second;
        
    }
};