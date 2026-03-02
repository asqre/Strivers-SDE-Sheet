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
    bool hasCycle(ListNode *head) {
        // return solve1(head);
        return solve2(head);
    }

private:
    // Brute force approach-using Hash map
    bool solve1(ListNode* head){
        unordered_map<ListNode*, bool> m;

        while(head != NULL){
            if(m.find(head) != m.end()){
                return true;
            }

            m[head] = true;
            head = head -> next;
        }

        return false;
    }

    // using Hare and tortoise Method
    bool solve2(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;

        do{
            if(fast == NULL || fast -> next == NULL){
                return false;
            }
            slow = slow -> next;
            fast = fast -> next -> next;
        }while(slow != fast);

        return true;
    }

};