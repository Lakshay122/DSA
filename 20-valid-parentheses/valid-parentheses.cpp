class Solution {
public:
    bool isValid(string s) {

        // so, let's resolve by  stack
        // we simply push the value if its open
        // if close tag is coming thren top element should be same closing
        // braket if yes then remove top element if not same return false in end
        // if stack is empty return true otherwise false

        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            // first check is opening tag
            char temp = s[i];
            cout<<temp<<endl;
            if (temp == '(' || temp == '{' || temp == '[') {
                cout<<temp<<"int"<<endl;
                st.push(temp);
            } else {
                // if close simple check
                if(st.empty()) return false;
                char prevEle = st.top();
                cout<<"prevElement"<<prevEle<<endl;
                if (temp == ')' && prevEle == '(') {
                    st.pop();
                }
               else if (temp == '}' && prevEle == '{') {
                    st.pop();
                }
               else if (temp == ']' && prevEle == '[') {
                    st.pop();
                } else{

                    return false;
                }
            }
        }
        // cout << st.top();
        return st.empty();
    }
};