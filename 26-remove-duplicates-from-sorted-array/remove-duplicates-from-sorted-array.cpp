class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // so logic is very simple for this 
        // take 2 pointer 
        // one is at the 0 and other is at 1 index
        // 2nd pointer is used ot check the unique value 
        // 1st pointer is used to set the unique value in sequence

        int length = nums.size();

        int firstPointer = 0;
        // int secondPointer = 1;
        int ans = 1;
        for(int i=1;i<length;i++){
            if(nums[i]!=nums[i-1]){
                nums[firstPointer+1] = nums[i];
                firstPointer++;
                ans++;
            }
        }
       return ans;
    }
};