class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // so, are going to solve this quesiton using kadane's algo
        // for that take min and max product bestSol subarray

        int ans = INT_MIN;
        int maxBestSol = 1;
        int minBestSol = 1;

        for(int i = 0;i<nums.size();i++){
            int v1 = maxBestSol*nums[i];
            int v2 = minBestSol*nums[i];
            maxBestSol = max(nums[i],max(v1,v2)); //3
            minBestSol = min(nums[i],min(v1,v2)); //3
            // minBestSol = min(minBestSol*nums[i], nums[i]);  // -6

            ans = max(ans,max(maxBestSol, minBestSol)); //-2
        }
        return ans;
    }
};