class Solution {
public:
    int maxNumberOfBalloons(string ransomNote, string magazine="balloon") {
        unordered_map<char,int> ransomMp;
        unordered_map<char,int> magazineMp;

        int ans = INT_MAX;
        for(int i=0;i<ransomNote.size();i++) ransomMp[ransomNote[i]]++;
        for(int i=0;i<magazine.size();i++) magazineMp[magazine[i]]++;
        
        for(auto i: magazineMp){

            if(i.second>ransomMp[i.first]) return 0;
            ans = min(ans, ransomMp[i.first]/i.second);
            
        }
        
        return ans==INT_MAX ? 0:ans;
    }
};