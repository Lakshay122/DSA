class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int low = 0;
        unordered_map<int,int> mp;
        int ans=INT_MIN;
        for(int high=0;high<nums.size();high++){
            mp[nums[high]]++;

            while(mp[0]>k){
                mp[nums[low]]--;
                if(mp[nums[low]]==0) mp.erase(nums[low]);
                low++;
            }
            ans=max(ans, high-low+1);
        }
        return ans;
    }
};