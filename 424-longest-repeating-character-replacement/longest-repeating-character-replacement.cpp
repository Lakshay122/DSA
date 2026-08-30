class Solution {
public:
    int maxValue(unordered_map<char, int>& mp) {
        return max_element(mp.begin(), mp.end(),
            [](const auto& a, const auto& b) {
                return a.second < b.second;
            })->second;
    }
    int characterReplacement(string s, int replace) {
        int low=0;
        int ans = INT_MIN;
        unordered_map<char, int> mp;
        for(int high = 0;high<s.size();high++){
            mp[s[high]]++;
            int k = high-low+1;
            int diff = k-maxValue(mp);
            // they say increase low till we have unique characters 
            while(diff>replace){
                mp[s[low]]--;
                if(mp[s[low]]==0)  mp.erase(s[low]);
                low++;
                k=high-low+1;
                diff=k-maxValue(mp);
            }
            // then its ans
            ans=max(ans,high-low+1);
        }
        // if(mp.size()==1&& ans==INT_MIN) return mp[s[0]];
        if(ans==INT_MIN) return 0;
        return ans;
    }
};