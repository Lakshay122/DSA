/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        cout<<"test";
        ListNode* ans=nullptr;
        
        // if(ans) cout<<"test";
        ListNode* currPointer=nullptr;
        int carry = 0;
        while(l1!=NULL || l2!=NULL){
            // get its ans 
            int sum = 0;
            
            if(l1!=NULL){
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2!=NULL){
                sum+=l2->val;
                l2=l2->next;
            }

            sum += carry;
    
            
            // check is 2 digit or one digit 
            if(sum/10==0){
                ListNode* temp = new ListNode(sum);
                if(currPointer!=NULL){
                   currPointer->next = temp;
                   currPointer = temp;
                }
                else{
                    ans = temp;
                    currPointer = temp;
                } 
                carry =0;
            }
            else {
                ListNode* temp = new ListNode(sum%10);
                if(currPointer!=NULL){
                   currPointer->next = temp;
                   currPointer = temp;
                }
                
                else{
                    ans = temp;
                    currPointer = temp;
                } 
                carry = 1;
            }
            

        }
        if(carry){
            ListNode* temp = new ListNode(carry);
             currPointer->next = temp;
                   currPointer = temp;
        }
        return ans;
    }
};