class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
       // using 2 pointer approach
       // so, our apprach is very simple 
       // initialize 2 pointer one from 0 and n-1 index
       // if square of first pointer is more that square of 2nd one then simple 
       // put that first pointer value in res vector using k index
       // other wise put 2nd pointer value in res vector using k index 

       vector<int> res(nums.size());
       int firstPointer = 0;
       int secondPointer = nums.size()-1;
       int resIndex = nums.size()-1;
       while(firstPointer<=secondPointer){
        int firstPointerValue = nums[firstPointer]*nums[firstPointer];
        int secondPointerValue = nums[secondPointer]*nums[secondPointer];
        if(firstPointerValue>secondPointerValue){
            res[resIndex--] = firstPointerValue;
            firstPointer++;
        }
        else {
            res[resIndex--] = secondPointerValue;
            secondPointer--;
        }
       }
        return res;
    }
};