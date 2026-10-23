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

  
    ListNode* rotateRight(ListNode* head, int k) {
        int n = 0;
        if(!head) return head;
        ListNode* temp = head;
        
        while(temp){
            temp=temp->next;
            n++;
        }
        k = n-(k%n);
        if(k==n) return head;
        temp = head;
        int currentIndex = 1;
        while(currentIndex<k){
            temp=temp->next;
            currentIndex++;
        }
        ListNode* startRot = temp->next;
        ListNode* startRotTrav = temp->next;
        temp->next=nullptr;
        while(startRotTrav->next){
            startRotTrav=startRotTrav->next;
        }
        startRotTrav->next=head;
        return startRot;
       
        
    }
};