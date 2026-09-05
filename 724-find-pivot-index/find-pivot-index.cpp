class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int totalSum = 0;
        int subArraySum = 0;
        for(int i=0;i<nums.size();i++) totalSum+=nums[i];
        for(int i=0;i<nums.size();i++) {
            if(2*subArraySum==totalSum-nums[i]) return i;
            subArraySum += nums[i];
        }
        return -1;
        
    }
};