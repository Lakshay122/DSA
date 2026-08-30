class Solution {
public:
    int lengthOfLongestSubstring(string s) {
         // code here
        int low=0;
        int ans = INT_MIN;
        unordered_map<char, int> mp;
        for(int high = 0;high<s.size();high++){
            mp[s[high]]++;
            int k = high-low+1;
            // they say increase low till we have unique characters 
            while(mp.size()<k){
                mp[s[low]]--;
                if(mp[s[low]]==0)  mp.erase(s[low]);
                low++;
                k=high-low+1;
            }
            // then its ans
            ans=max(ans,high-low+1);
        }
        // if(mp.size()==1&& ans==INT_MIN) return mp[s[0]];
        if(ans==INT_MIN) return 0;
        return ans;
    }
};