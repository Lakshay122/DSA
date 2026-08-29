class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT_MAX;
        int low=0;
        int high = 0;
        int sum=0;
        while(high<nums.size()){
            sum+=nums[high];
            while(sum>=target){
                int distance = high-low+1;
                ans = min(ans,distance);
                sum-=nums[low];
                low++;
            }
            high++;
        }
        if(ans==INT_MAX) return 0;
        return ans;
    }
};