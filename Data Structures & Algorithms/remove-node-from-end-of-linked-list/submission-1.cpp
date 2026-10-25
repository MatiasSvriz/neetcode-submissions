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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
       vector<ListNode*> nodes;
        ListNode* actual = head;

        while (actual != nullptr) {
            nodes.push_back(actual);
            actual = actual->next;
        }

        int longitud = nodes.size();
        int posicion = longitud - n;

        // Si eliminamos el primero, cambia la cabeza.
        if (posicion == 0) {
            head = head->next;
        }else{
            nodes[posicion - 1]->next = nodes[posicion]->next;
        }

        return head;

    }
};
