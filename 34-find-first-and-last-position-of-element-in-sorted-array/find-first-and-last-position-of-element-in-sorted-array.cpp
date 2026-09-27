class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int firstOcc = INT_MAX;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                firstOcc = min(firstOcc, mid);
                right = mid - 1;
            } else if (nums[mid] >= target) {

                right = mid - 1;

            } else
                left = mid + 1;
        }
        if (firstOcc == INT_MAX)
            return { -1, -1 };

        left = 0;
        right = nums.size() - 1;
        int secondOcc = INT_MIN;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                secondOcc = max(secondOcc, mid);
                left = mid + 1;
            } else if (nums[mid] >= target) {
                right = mid - 1;
            } else
                left = mid + 1;
        }
        return {firstOcc,secondOcc};
    }
};