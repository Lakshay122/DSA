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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1)
            return head;
        int start = 1;
        int n = 0;
        // let's calculate length first
        ListNode* temp = head;
        while (temp) {
            n++;
            temp = temp->next;
        }

        ListNode* prev = NULL;
        ListNode* ans = NULL;
        ListNode* startNode = NULL;
        ListNode* pointerToStart=NULL;
        while (start <= n) {
            int end = start + k - 1;
            if (end > n)
                break;
            startNode = head;
            if(prev )
            cout<<start<<" "<<end<<prev->val<<endl;

            while (start <= end) {
                ListNode* next = head->next;
                head->next = prev;
                prev = head;
                head = next;
                start++;
            }

            if (!ans) {
                ans = prev;
            }
                startNode->next = head;
            if(pointerToStart) {pointerToStart->next=prev;
            }

            pointerToStart=startNode;

            prev=startNode;
        }
        return ans;
    }
};