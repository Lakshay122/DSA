/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // so, my approach to solve this 
        // use slow and fast pattern
        // very simple first fetch the is cycle present or not 
        // if cycle is present then simple 
        // we back the start from head then move fast and slow by 1 
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            
            if(fast==slow){
                // cout<<"fast"<<fast->val<<" "<<"slow" << slow->val<<endl;
                slow=head;
                while(true){
                    if(slow == fast) return slow;
                    slow=slow->next;
                    fast=fast->next;
                }
            }
        }
        return NULL;
    }
};