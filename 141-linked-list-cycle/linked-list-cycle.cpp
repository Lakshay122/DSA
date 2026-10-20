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
    // using floyd algo
    bool hasCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(slow!=NULL && fast!=NULL &&fast->next!=NULL && fast->next->next!=NULL && slow->next!=NULL){
            slow  = slow->next;
            fast  = fast->next->next;
            if(slow== fast) return true;
        }
        return false;
    }

    // // using extra space
    // bool hasCycle(ListNode* head) {
    //     unordered_set<ListNode*> s;

    //     while (head != NULL) {
    //         // is head already exits in the set
    //         if (s.count(head))
    //             return true;
    //         s.insert(head);
    //         head = head->next;
    //     }
    //     return false;
    // }
};