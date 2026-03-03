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
    ListNode* rotateRight(ListNode* head, int k) {
        return solve1(head, k);
    }

private:
    ListNode* solve1(ListNode* head, int k){
        int n = len(head);

        if(head == NULL || head -> next  == NULL || (k % n == 0)){
            return head;
        }

        k %= n;

        return rotateList(head, n-k);;
    }

    ListNode* rotateList(ListNode* head, int n){
        ListNode* temp = head;

        while(--n){
            temp = temp -> next;
        }

        ListNode* newhead = temp -> next;
        temp -> next = NULL;
        temp = newhead;

        while(temp -> next != NULL){
            temp = temp -> next;
        }

        temp -> next = head;

        return newhead;
    }

    int len(ListNode* head){
        if(head == NULL){
            return 0;
        }

        return 1 + len(head -> next);
    }
};