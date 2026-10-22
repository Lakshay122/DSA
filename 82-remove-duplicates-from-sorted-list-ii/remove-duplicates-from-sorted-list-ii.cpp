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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next)
            return head;
        // so first approach make vector save last vlaue
        // make the last value on top
        // so, supose we have hte one so, if value is equal to teh last vclaue
        // in any case top is 1, it see one again make boolean value to false
        // and update h node till its value is 1
        vector<int> uniqueValue;
        ListNode* temp = head->next;
        int top = head->val;
        int count = 1;
        ListNode* dummy = new ListNode(0);
        ListNode* ans = dummy;
        while (temp) {
            // if(top==tem->val) count++;
            while (temp&& temp->val == top) {
                count++;
                temp = temp->next;
            }
            if(!temp) break;
            if (count == 1) {
                uniqueValue.push_back(top);
                ans->next = new ListNode(top);
                ans = ans->next;
            }
            top = temp->val;
            temp=temp->next;
            count = 1;
        }
         if (count == 1) {
                uniqueValue.push_back(top);
                ans->next = new ListNode(top);
                ans = ans->next;
            }

        return dummy->next;
    }
};