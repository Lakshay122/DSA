class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int remainingLength = maxWidth;
        int countSpace = 0;
        for (int i = 0; i < words.size(); i++) {
            if (remainingLength == maxWidth) {
                ans.push_back(words[i]);
                remainingLength -= words[i].size();
            } else if (words[i].size() + 1 <= remainingLength) {
                if (remainingLength == maxWidth) {
                    // need to create new
                    ans.push_back(words[i]);
                    remainingLength -= words[i].size();
                } else {
                    countSpace++;
                    ans[ans.size() - 1] += " ";
                    ans[ans.size() - 1] += words[i];
                    remainingLength -= words[i].size();
                    remainingLength -= 1;
                }
            } else {
                // if()
                if (countSpace == 0) {
                    while (remainingLength) {
                        ans[ans.size() - 1] += " ";
                        remainingLength--;
                    }

                } else {
                    // need ot find total space should be there
                    int reminder = remainingLength % countSpace;
                    int numberOfSpaceReq;
                    int numberOfExtraFirstSpace = 0;
                    if (reminder == 0) {
                        numberOfSpaceReq = remainingLength / countSpace;
                    } else {
                        numberOfSpaceReq = remainingLength / countSpace;
                        numberOfExtraFirstSpace = reminder;
                    }
                    string s = "";

                    for (int i = 0; i < ans[ans.size() - 1].size(); i++) {
                        char currentIndexVal = ans[ans.size() - 1][i];
                        s += currentIndexVal;
                        if (currentIndexVal == ' ') {

                            int temp = numberOfSpaceReq;
                            while (temp) {
                                s += " ";
                                temp--;
                            }
                            if (numberOfExtraFirstSpace) {
                                s += " ";
                                numberOfExtraFirstSpace--;
                            }
                        }
                    }

                    ans[ans.size() - 1] = s;
                }
                ans.push_back(words[i]);
                remainingLength = maxWidth - words[i].size();
                countSpace = 0;
                cout << remainingLength << endl;
            }
        }

        if (remainingLength) {

            while (remainingLength) {
                ans[ans.size() - 1] += " ";
                // s += " ";
                remainingLength--;
            }
        }
        // for (int i = 0; i < ans[ans.size() - 1].size(); i++) {
        //     char currentIndexVal = ans[ans.size() - 1][i];
        //     s += currentIndexVal;
        //     if (currentIndexVal == ' ') {
        //         isChange = true;
        //         int temp = numberOfSpaceReq;
        //         while (temp) {
        //             s += " ";
        //             temp--;
        //         }
        //         if (i + 1 <= numberOfExtraFirstSpace) {
        //             s += " ";
        //         }
        //     }
        // }

        // for(int i =0;i<ans.size();i++){
        //     string arr[] = ans[i].split(" ")
        // }
        return ans;
    }
};