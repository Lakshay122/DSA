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
    int arraySum(vector<int> &nums){
        int sum= 0;
        for(int i=0;i<nums.size();i++) sum+=nums[i];
        return sum;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxSum = maxSubarray(nums);
        int minSum = minSubarray(nums);
        int fullSum = arraySum(nums);

        if(fullSum==minSum) return maxSum; // for all neg values
        return max(maxSum, fullSum-minSum);
    }
};