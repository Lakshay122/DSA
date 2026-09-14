class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
       // so the solution is very simple 
       // we double the array hypothetical not in real 
       // the time complex. -> 4N(2n for outer loop and 2n for stack)
       // space comp: 2N(stack) + N(for ans)

       vector<int> ans;
       stack<int> st;

       int n = nums.size();
       for(int i=2*n-1;i>=0;i--){
        int actualIndex = i%n;
        int val = nums[actualIndex];
        while(!st.empty() && st.top()<=val) st.pop();
        if(i<n) ans.push_back(st.empty()?-1:st.top());
        st.push(val);
       }
       
       reverse(ans.begin(), ans.end());
       return ans; 
      
    }
};