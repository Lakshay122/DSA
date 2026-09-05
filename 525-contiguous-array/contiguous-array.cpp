class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int countZero = 0;
        int countOne = 0;
        int ans = 0;
        unordered_map<int,int> freq;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) countZero++;
            else countOne++;
            int diff = countZero-countOne;
            if(diff==0) ans = i+1;
            if(freq.find(diff)!=freq.end()){
                int len = i-freq[diff];
                ans=max(ans,len);
            }
            else freq[diff]=i;
        }
        return ans;
    }
};