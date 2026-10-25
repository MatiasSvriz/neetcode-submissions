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
        
        unordered_set<ListNode*> seen;

        ListNode* actual = head;

        while(actual != nullptr){

            if(seen.count(actual) > 0){
                return true;
            }

            seen.insert(actual);

            actual = actual->next;

        }

        return false;

    }
};
