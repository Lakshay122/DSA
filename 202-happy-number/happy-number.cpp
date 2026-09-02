class Solution {
public:
    int sumofSquare(int n){
        int sum = 0;
        while(n>0){
            int rem = n%10;
            n/=10;
            sum+=rem*rem;
        }
        return sum;
    }
    bool isHappy(int n) {
        // i'm going to solve this question use slow and fast pointer
        // slow pointer fetch next value & fast pointer fetch next to next value 
        // if its match somewhere it means cycle is present but value should not be 1 
        // we are going to fetch till 1 
        // bcs there is only 2 case there
        // give number is happy or not
        // if happy then fast should be 1 in future 
        // if not then slow should be equal to fast
        int slow = n;
        int fast = n;

        while(fast!=1){
            slow = sumofSquare(slow);
            fast = sumofSquare(fast);
            fast = sumofSquare(fast);

            if(slow == fast && fast!=1) return false;

        }
        return true;
    }
};