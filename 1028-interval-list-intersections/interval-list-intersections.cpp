class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {

        // so,my logic is very simple we are going to use the 2 pointer 
        // first we check is intersection exists in i and j 
        // how we check intersection 
        // if end of firstList i pointer is lies in range of the second list of j pointer or vice versa for secondlist endpoint 
        // then for find intersection 
        // take max from start pointer and min from endpointer
        // now which one we need to increase 
        // whose end is smaller we increase that pointer 
        int i = 0, j = 0;
        vector<vector<int>> res;
        while(i<firstList.size() && j<secondList.size())
        {

            int start1=firstList[i][0];
            int end1=firstList[i][1];
            
            int start2 = secondList[j][0];
            int end2 = secondList[j][1];

            // now check is intersection exists
            if((end1 >= start2 && end1 <= end2 ) || (end2>=start1 && end2<=end1)){
                int intersectI = max(start1, start2);
                int intersectJ = min(end1, end2);
                res.push_back({intersectI, intersectJ});
            }
            if(end1>=end2){
                j++;
            }
            else i++;
        }
        return res;
    }
};