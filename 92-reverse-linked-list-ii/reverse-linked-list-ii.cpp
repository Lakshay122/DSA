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
    ListNode* rev(ListNode* head, int count) {
        ListNode* prev = NULL;
        while (count) {
            ListNode* temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;
            count--;
        }
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* before = NULL;
        ListNode* end = NULL;
        int currentIndex = 1;
        // we are trying to fint eh first and last node and before first node
        // and adfter last node
        ListNode* beforeFirst = NULL;
        ListNode* afterLast = NULL;
        ListNode* temp = head;
        while (currentIndex <= right) {
            if (currentIndex == left || currentIndex == right) {
                if (currentIndex == left) {
                    before = temp;
                }
                if (currentIndex == right) {
                    end = temp;
                    afterLast = temp->next;
                }
            } else {
                if (currentIndex==left-1) {
                    beforeFirst = temp;
                }
            }
            temp = temp->next;
            currentIndex++;
        }

        // now call for rev
        ListNode* revPointer = rev(before, right - left + 1);

        if (beforeFirst == NULL) {
            before->next = afterLast;
            return revPointer;
        }
        beforeFirst->next = revPointer;
        before->next = afterLast;
        return head;
    }
};