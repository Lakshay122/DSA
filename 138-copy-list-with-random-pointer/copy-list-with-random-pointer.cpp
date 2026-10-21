/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* ans = nullptr;
        Node* ansTail = nullptr;
        unordered_map<Node*,Node*> indexPointer;
        while (head != nullptr) {
            cout << head << endl;
            Node* temp = new Node(head->val);
            Node* tempRandom = nullptr;
            if (head->random) {
                cout << "random val " << head->random->val << endl;
                tempRandom = head->random;
            }
            temp->random = tempRandom;
            indexPointer[head] = temp;

            if (!ans) {
                ans = temp;
                ansTail = temp;
            } else {
                ansTail->next = temp;
                ansTail = temp;
            }
            head = head->next;
        }
        ansTail = ans;
        while (ansTail != NULL) {
            if (ansTail->random) {
                ansTail->random = indexPointer[ansTail->random];
            }
            ansTail = ansTail->next;
        }

        return ans;
    }
};