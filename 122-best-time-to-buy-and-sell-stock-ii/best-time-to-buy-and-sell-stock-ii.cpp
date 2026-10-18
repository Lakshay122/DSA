class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // my logic is very simple , sees 
        // we are goign to save one valu as min , if current value is equal to that value do nothgin , 
        // if current value> min// then we can sell and add that diff in our ans and make new min current
        // if current < min then update min
        int mini = prices[0];
        int ans = 0;
        for(auto current: prices){
            if(current > mini) {
                ans+=(current-mini);
                mini = current;
            }
            else{
                mini = current;
            }
        }
        return ans;

    }
};