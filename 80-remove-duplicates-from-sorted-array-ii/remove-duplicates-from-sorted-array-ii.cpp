class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k=1;
        int i=1;
        bool countRep = false;
        while(i<nums.size())
        {
            // cout<<k<<" "<<i<< " "<< countRep<<endl;
            if(nums[i]==nums[i-1]){
                if(!countRep){
                    nums[k]= nums[i];
                    k++;
                    countRep=true;
                }
            }
            else {
                countRep=false;
                nums[k]= nums[i];
                k++;
            }
            i++;
        }
        return k;
    }
};