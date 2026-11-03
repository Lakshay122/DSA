class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        unordered_set<string> wordListSet(wordList.begin(), wordList.end());
        unordered_set<string> vis;
        queue<string> q;

        // check one edge if endWord is not word list return 0;
        bool isPresent = false;
        for (int i = 0; i < wordList.size(); i++) {
            if (wordList[i] == endWord) {
                isPresent = true;
                break;
            }
        }
        if (!isPresent)
            return 0;
        // cout<<"pass"<<endl;    
        int steps = 1;

        q.push(beginWord);
        vis.insert(beginWord);
        while (!q.empty()) {
            int size = q.size();
            steps++;
            while (size--) {
                string top = q.front();
                if (top == endWord)
                    return steps-1;
                q.pop();

                for (int i = 0; i < top.size(); i++) {
                    string temp = top;
                    for (int j = 0; j < 26; j++) {
                        top[i] = 'a' + j;
                        // cout<<"top"<<top<<endl;
                        if ((!vis.count(top)) && wordListSet.count(top)) {
                            // cout<<top<<endl;
                            q.push(top);
                            vis.insert(top);
                        }
                    }
                    top = temp;
                }
                // steps++;
            }
        }
        return 0;
    }
};