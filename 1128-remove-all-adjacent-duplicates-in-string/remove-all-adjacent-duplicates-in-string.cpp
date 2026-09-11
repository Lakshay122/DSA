class Solution {
public:
    string removeDuplicates(string s) {
        // let's resolve by stack
        stack<char> st;
        string ans;
        st.push(s[0]);

        for (int i = 1; i < s.size(); i++) {
            char temp = s[i];
            if (st.empty()) {
                st.push(temp);
            } else {
                char prevEle = st.top();
                if (temp == prevEle)
                    st.pop();
                else st.push(temp);
            }
        }

        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};