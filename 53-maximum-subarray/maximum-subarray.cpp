class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // we have lot of solution to solve this 
        // we are going to implement with nested loop then kadane's algo

        // int ans = INT_MIN;
        // for(int i = 0;i<nums.size();i++){
        //     int sum = nums[i];
        //     ans=max(ans,sum);
        //     for(int j=i+1;j<nums.size();j++){
        //         sum+=nums[j];
        //         ans=max(ans,sum);
        //     }
        // }
        // return ans;


        // kanden's algo 
        // need to think like current index is last index 
        // should we need to add into prev or take current one as best solution 

        int ans=INT_MIN;
        int bestSol = 0;
        for(int i =0;i<nums.size();i++){
            bestSol = max(bestSol+nums[i], nums[i]);
            ans = max(bestSol, ans);
        }
        return ans;
    }

};