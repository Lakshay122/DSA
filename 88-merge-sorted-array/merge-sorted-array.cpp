class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // lot of methods
        //  go direct with simple soluion
        //  2 pointer i and j -> i on nums1, j on nums2
        //  which one is small put it on ans, and incrase that i or j by 1
        //  then paste ans array in nums1

        int i = 0;
        int j = 0;
        vector<int> ans;
        while (i < m && j < n) {
            if (nums1[i] < nums2[j]) {
                ans.push_back(nums1[i]);
                i++;
            } else {
                ans.push_back(nums2[j]);
                j++;
            }
        }
        while (i < m) {
            ans.push_back(nums1[i]);
            i++;
        }
        while (j < n) {
            ans.push_back(nums2[j]);
            j++;
        }
        for (int i = 0; i < m + n; i++) {
            nums1[i] = ans[i];
        }
        // return ans;
    }
};