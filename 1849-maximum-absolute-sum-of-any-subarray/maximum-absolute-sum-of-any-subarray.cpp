class Solution {
public:
    int maxSubarray(vector<int>& nums){
        int ans = INT_MIN;
        int bestSolution = 0;
        for(int i=0;i<nums.size();i++){
            bestSolution=max(bestSolution+nums[i], nums[i]);
            ans = max(ans,bestSolution);
        }
        return ans;
    }
    int minSubarray(vector<int>& nums){
        int ans = INT_MAX;
        int bestSolution = 0;
        for(int i=0;i<nums.size();i++){
            bestSolution=min(bestSolution+nums[i], nums[i]);
            ans = min(ans,bestSolution);
        }
        return ans;
    }
    int maxAbsoluteSum(vector<int>& nums) {
        int maxSum = maxSubarray(nums);
        int minSum = abs(minSubarray(nums));
        return max(maxSum, minSum);
    }
};