class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 1;
        int i = 1;
        while (i < nums.size()) {
            if (nums[i] != nums[i-1]) {
                
                nums[k]=nums[i];
                k++;
            }
            
            i++;
        }
        return k;
    }
};