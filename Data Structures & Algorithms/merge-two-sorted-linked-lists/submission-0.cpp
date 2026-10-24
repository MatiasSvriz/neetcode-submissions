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
        
        if(list1 == nullptr){
            return list2;
        }

        if(list2 == nullptr){
            return list1;
        }

        ListNode* inicio;

        if(list1->val <= list2->val){

            inicio = list1;
            list1 = list1->next;

        }else{

            inicio = list2;
            list2 = list2->next;

        }

        ListNode* referenciaAlUltimo = inicio;

        while(list1 != nullptr && list2 != nullptr){

            if(list1->val <= list2->val){

                referenciaAlUltimo->next = list1;
                list1 = list1->next;

            }else if(list2->val <= list1->val){

                referenciaAlUltimo->next = list2;
                list2 = list2->next;

            }

            referenciaAlUltimo = referenciaAlUltimo->next;

        }

        if(list1 != nullptr){
            referenciaAlUltimo->next = list1;
        }

        if(list2 != nullptr){
            referenciaAlUltimo->next = list2;
        }

        return inicio;

    }
};
