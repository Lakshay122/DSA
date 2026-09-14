class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> ransomMp;
        unordered_map<char,int> magazineMp;

        for(int i=0;i<ransomNote.size();i++) ransomMp[ransomNote[i]]++;
        for(int i=0;i<magazine.size();i++) magazineMp[magazine[i]]++;

        for(auto i: ransomMp){
            if(i.second>magazineMp[i.first]) return false;
        }
        
        return true;
    }
};