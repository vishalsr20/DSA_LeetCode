class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>st;
        int n = s.length();
        for(int i=0; i<n; i++){
            char ch = s[i];
            if(st.empty()){
                st.push(ch);
            }else{
                if(st.top() != ch){
                    st.push(ch);
                }else{
                    while(!st.empty() && st.top() == ch){
                        st.pop();
                    }
                }
            }

        }
        string ans ="";
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());

        return ans;
    }
};