class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // so, my apporach is very simple to resolve this question using 2 pointer
        // take 2 pointer ons start from 0 and other is from 1 index
        // simple first one take care of position and 2nd one is take of the uniqueness 
        // then there is one count as well that simply check is 2 repeation done with current element or not 

        int currentElementCount = 1;
        int i = 0;
        int j = 1;
        int length= nums.size();
        int ans=1;
        while(i<length && j<length){
            cout<<i<<j<<endl;
            if(nums[j]==nums[j-1]){
                if(currentElementCount==1) {
                    nums[i+1]=nums[j];
                    i++;
                    j++;
                     ans++;
                    currentElementCount++;
                }
                else j++;
            }
            else {
                nums[i+1]= nums[j];
                ans++;
                i++;
                j++;
                currentElementCount=1;
            }
        }
        cout<<i<<j<<endl;
 if(currentElementCount==2) {
    nums[i]= nums[j-1];
    //  ans++;
     }
        return ans;
    }
};