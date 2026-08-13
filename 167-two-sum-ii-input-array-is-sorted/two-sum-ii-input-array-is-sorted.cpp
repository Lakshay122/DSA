class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // so the logic is like we have the sorted array so, if we've the sorted
        // array we can simple use the 2 pointer approach 
        

        //[2,7,11,15]
        // our simple logic 2pointer 
        // we use one pointer on start and one is at end 
    
        // use while loop till they are crrossing or equal to each other 
        // if sum of there value is more than target then dec. j pointer 
        // if sum is less ten then inc. i pointer 1 
        // once the equal to target we simply return the indexes

        int length = numbers.size();

        int start = 0;
        int end = length-1;

        vector<int> ans;

        while (start<end){
            int sum  = numbers[start] + numbers[end];
            if(sum == target) {
                ans.push_back(start+1);
                ans.push_back(end+1);
                break;
            }
            else if(sum>target) end--;
            else start++;
        }

        return ans;

    }
};