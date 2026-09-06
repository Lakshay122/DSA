class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int countOnes = 0;
        int ans = 0;
        for(auto i:nums){
            if(i ==1)countOnes++;
           else {
            ans = max(ans,countOnes);
            countOnes =0 ;
            }
        }
        ans = max(ans,countOnes);
        return ans;
    }
};