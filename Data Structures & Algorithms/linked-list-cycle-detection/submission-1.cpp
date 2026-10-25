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
    bool hasCycle(ListNode* head) {
        
        ListNode* lento = head;
        ListNode* rapido = head;

        while(rapido != nullptr && rapido->next != nullptr){

            lento = lento->next;
            rapido = rapido->next->next;

            if(lento == rapido){
                return true;
            }

        }

        return false;

    }
};
