class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        if (nums.size() == 1)
            return 0;
        if (nums.size() == 2) {
            if (nums[0] > nums[1])
                return 0;
            else
                return 1;
        }
        while (left <= right) {
            int mid = left + (right - left) / 2;

            // we need to check mid with its prev and next value
            //  cout <<mid<<endl;
            if (mid - 1 < 0) {
                left = mid + 1;
                if (nums[mid] > nums[mid + 1])
                    return mid;
            } else if (mid + 1 >= nums.size()) {

                right = mid - 1;
                if (nums[mid] > nums[mid - 1])
                    return mid;
            } else if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
                return mid;
            else if (nums[mid] > nums[mid + 1])
                right = mid - 1;
            else
                left = mid + 1;
        }
        return -1;
    }
};
