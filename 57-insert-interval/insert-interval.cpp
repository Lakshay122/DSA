class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {
        vector<vector<int>> insertIntervals;
        vector<vector<int>> res;

        bool isInserted = false;
        for (int i = 0; i < intervals.size(); i++) {
            if (!isInserted && intervals[i][0] >= newInterval[0]) {
                insertIntervals.push_back(newInterval);
                isInserted = true;
            }

            insertIntervals.push_back(intervals[i]);
        }
        if(!isInserted) insertIntervals.push_back(newInterval);


        int start1=insertIntervals[0][0];
        int end1 = insertIntervals[0][1];

        for(int i=1;i<insertIntervals.size();i++){
            int start2=insertIntervals[i][0];
            int end2=insertIntervals[i][1];
            if(end1>=start2){
                end1  = max(end1, end2);
            }else{
                res.push_back({start1,end1});
                start1=start2;
                end1=end2;
            }
        }
        res.push_back({start1,end1});
        return res;
    }
};