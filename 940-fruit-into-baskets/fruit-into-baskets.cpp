class Solution {
public:
    int totalFruit(vector<int>& fruits) {
         // code here
        int low=0;
        int ans = INT_MIN;
        unordered_map<int, int> mp;
        int k=2;
        for(int high = 0;high<fruits.size();high++){
            mp[fruits[high]]++;
            while(mp.size()>k){
                mp[fruits[low]]--;
                if(mp[fruits[low]]==0)  mp.erase(fruits[low]);
                low++;
                
            }
            if(mp.size()==k) ans=max(ans,high-low+1);
            
        }
        if(mp.size()==1&& ans==INT_MIN) return mp[fruits[0]];
        if(ans==INT_MIN) return -1;
        return ans;
    }
};