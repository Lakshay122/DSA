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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ans = nullptr;
        ListNode* ansTail = nullptr;

        while (list1!= NULL && list2!= NULL) {
            if (list1->val <= list2->val) {
                if (!ans) {
                    ans = list1;
                    ansTail = list1;
                } else {
                    ansTail->next = list1;
                    ansTail = list1;
                }
                list1 = list1->next;
            } else {
                if (!ans) {
                    ans = list2;
                    ansTail = list2;
                } else {
                    ansTail->next = list2;
                    ansTail = list2;
                }
                list2 = list2->next;
            }
        }

        while (list1!= NULL) {
            if (!ans) {
                ans = list1;
                ansTail = list1;
            } else {
                ansTail->next = list1;
                ansTail = list1;
            }
            list1 = list1->next;
        }

        while (list2!= NULL) {
            if (!ans) {
                ans = list2;
                ansTail = list2;
            } else {
                ansTail->next = list2;
                ansTail = list2;
            }
            list2 = list2->next;
        }

        return ans;
    }
};