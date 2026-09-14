class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // same as next greate elementjust need to save index as well in stack using pair
        vector<int> ans;
        stack<pair<int,int>> st;
        int n = temperatures.size();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top().first<=temperatures[i]) st.pop();
            if(st.empty()) ans.push_back(0);
            else ans.push_back(st.top().second-i);
            st.push({temperatures[i], i});
        } 
        reverse(ans.begin(), ans.end());
        return ans;
    }
};