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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // so by  using some space like vector and store list 1 value
        vector<ListNode*> listAVal;
        while(headA){
            listAVal.push_back(headA);
            headA=headA->next;
        }

        while(headB){
            if (find(listAVal.begin(), listAVal.end(), headB) != listAVal.end()) {
                return headB;
            }
            headB=headB->next;
        }
        return nullptr;
        
    }
};