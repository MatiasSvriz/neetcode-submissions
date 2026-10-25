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
    void reorderList(ListNode* head) {

        if(head == nullptr){
            return;
        }

        vector<ListNode*> nodes;
        ListNode* actual = head;

        while(actual != nullptr){
            nodes.push_back(actual);
            actual = actual->next;
        }

        int n = nodes.size();

        int left = 0;
        int right = n - 1;

        while(left < right){

            nodes[left]->next = nodes[right];

            left ++;

            if(left == right){
                break;
            }

            nodes[right]->next = nodes[left];

            right --;
                
        }

         nodes[left]->next = nullptr;
        
    }
};
