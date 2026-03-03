/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    // Using Hare and Tortoise Algorithm
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        // detect a cycle
        do{
            if(fast == NULL || fast -> next == NULL){
                return NULL;
            }

            slow = slow -> next;
            fast = fast -> next -> next;
        }while(slow != fast);

        // find the node where cycle begins
        slow = head;

        while(slow != fast){
            slow = slow -> next;
            fast = fast -> next;
        }

        return slow; // fast
    }
};