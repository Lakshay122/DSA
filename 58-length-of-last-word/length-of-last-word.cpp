class Solution {
public:
    int lengthOfLastWord(string s) {
        s = s.substr(0, s.find_last_not_of(' ') + 1);

        int n = s.length();
        int count = 0;
        int i = n - 1;

        while (i >= 0) {
            if (s[i] == ' ') {
                break;
            }

            count++;
            i--;
        }

        return count;
    }
};