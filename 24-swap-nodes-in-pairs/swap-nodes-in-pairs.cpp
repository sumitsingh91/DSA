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
// class Solution {
// public:
//     ListNode* swapPairs(ListNode* head) {
        
//     }
// };
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // Base case: if less than 2 nodes left, no swapping needed
        if (!head || !head->next) {
            return head;
        }

        // Nodes to be swapped
        ListNode* first = head;
        ListNode* second = head->next;

        // Swapping links recursively
        first->next = swapPairs(second->next);
        second->next = first;

        // New head of the swapped pair is 'second'
        return second;
    }
};