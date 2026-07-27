class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>>st;
        int n = s.length();
        for(int i=0; i<n; i++){
            char ch = s[i];
            if(st.empty()){
                st.push({ch,1});
            }else{
                if(!st.empty() && st.top().first != ch){
                    st.push({ch,1});
                }else{
                    if(!st.empty() && st.top().second == k-1){
                        st.pop();
                    }else{
                        st.top().second++;
                    }
                }
            }
        }
        string ans;
        while(!st.empty()){
            ans.append(st.top().second,st.top().first);
            st.pop();
        }

        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};