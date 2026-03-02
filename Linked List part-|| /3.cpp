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
    ListNode* reverseKGroup(ListNode* head, int k) {
        return solve1(head, k);
    }

private:
    ListNode* solve1(ListNode* head, int k){
        ListNode* dummy = new ListNode(0);
        dummy -> next = head;
        ListNode* temp = dummy;

        int n = len(head);
        
        while(n >= k){
            pair<ListNode*, ListNode*> reverseNodeData = reversek(temp -> next, k);
            ListNode* newHead = reverseNodeData.first;
            ListNode* newTail = reverseNodeData.second;

            temp -> next = newHead;
            temp = newTail;

            n -= k;
        }

        return dummy -> next;
    }

    int len(ListNode* head){
        if(head == NULL){
            return 0;
        }

        return 1 + len(head -> next);
    }

    pair<ListNode*, ListNode*> reversek(ListNode* head, int k){
        ListNode* tail = head;
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;

        while(k--){
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }

        tail -> next = curr;
        return {prev, tail};
    }
};