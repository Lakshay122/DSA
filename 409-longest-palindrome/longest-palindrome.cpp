class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> mp;
        for(int i=0;i<s.size();i++) mp[s[i]]++;
        int ans = 0;
        bool isAnyOdd = false;
        for(auto i: mp){
            if(i.second%2==0) ans+=i.second;
            else {
                isAnyOdd=true;
                ans+=i.second-1;
            }
        }
        if(isAnyOdd) ans+=1;
        return ans;
    }
};