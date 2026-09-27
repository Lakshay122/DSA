class Solution {
public:
    int findMin(vector<int>& nums) {

        int left = 0;
        int right = nums.size() - 1;
        int ans = INT_MAX;
        while(left<=right) {
            int mid = left+(right-left)/2;
            if(nums[mid]>=nums[right]) {
                left=mid+1;
                ans = min(ans, nums[mid]);
            }
            else {
                right = mid-1;
                ans = min(ans, nums[mid]);
            }
        }
        return ans;
    }
};