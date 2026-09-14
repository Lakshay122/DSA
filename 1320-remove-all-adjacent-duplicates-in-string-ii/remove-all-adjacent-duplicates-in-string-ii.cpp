class Solution {
public:
    string removeDuplicates(string s, int k) {
        // so, the logic is simple using stack to
        // in stack we simply store the pair
        // first value in pair is storing string value 
        // second value storing +1 counter of top one if char is same 
        // after if top is counter is same as k then remove value till k length

        string ans;
        stack<pair<char,int>> st;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(st.empty() || st.top().first != s[i]){
                st.push({s[i],1});
            }
            else {
                if(st.top().second == k-1){
                    //it means now we need to remove all k-1 element from stack
                    for(int j=0;j<k-1;j++) st.pop();
                }
                else st.push({s[i], st.top().second+1});
            }
        }

        while(!st.empty()){
            ans+=st.top().first;
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};