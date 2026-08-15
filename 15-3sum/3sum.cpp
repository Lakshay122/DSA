class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // what ur approach to solve this question using 2 pointer 
        // so, we are going to find the pair whose target is -nums[i]
        // so, our qquestion is change to the 
        // find unique pairs whose target is that element but do this for all elements of the aray 

        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int n=nums.size();
        for(int i=0;i<n-2;i++){
            cout<<"firstone"<<i<<nums[i]<<endl;
            int target = -nums[i];
            cout<<i<<nums[i]<<target<<endl;

            int firstPointer = i+1;
            int secondPointer = n-1;

            while(firstPointer<secondPointer){
                int sum = nums[firstPointer]+nums[secondPointer];
                if(sum>target){
                    secondPointer--;
                }
                else if(sum<target) firstPointer++;
                else {
                    // we find the pair here
                    res.push_back({nums[i],nums[firstPointer],nums[secondPointer]});
                    firstPointer++;
                    secondPointer--;
                    // for safe from duplicate we update both index 
                    // but we move the index untill its same as prev
                    while(firstPointer<n && nums[firstPointer]==nums[firstPointer-1] ) firstPointer++;
                    while( secondPointer>=0 && nums[secondPointer]==nums[secondPointer+1] ) secondPointer--;
                }
               
            }
            while(i+1<n && nums[i]==nums[i+1]) i++;
        }
        return res;
    }
};