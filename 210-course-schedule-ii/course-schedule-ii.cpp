class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> gr(numCourses);
        vector<int> countIncomings(numCourses, 0);
        vector<int> ans;
        for (int i = 0; i < prerequisites.size(); i++) {
            gr[prerequisites[i][1]].push_back(prerequisites[i][0]);
            countIncomings[prerequisites[i][0]]++;
            // cout<<countIncomings[prerequisites[i][0]]<<endl;
        }

        for (int i = 0; i < numCourses; i++) {

            if (countIncomings[i] == 0) {

                int node = i;
                ans.push_back(node);
                for (int j = 0; j < gr[node].size(); j++) {
                    countIncomings[gr[node][j]]--;
                }
                countIncomings[i] = -1;
                i = -1;
            }
        }
        
        for (int i = 0; i < numCourses; i++) {
            cout << countIncomings[i] << endl;
            if (countIncomings[i] != -1)
            {
                ans.clear();

              return ans;
            }  
        }
        return ans;
    }
};