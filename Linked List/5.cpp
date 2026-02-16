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
        // return solve1(head, n);
        // return solve2(head, n);
        return solve3(head, n);
    }
private:
    int len(ListNode* head){
        if(head == NULL){
            return 0;
        }

        return 1 + len(head -> next);
    }

    ListNode* solve1(ListNode* head, int n){
        int x = len(head);
        if(x - n == 0) return head -> next;

        int count = 0;

        ListNode* dummy = new ListNode(0);
        dummy -> next = head;
        ListNode* temp = dummy;

        while(count < x - n){
            temp = temp -> next;
            count++;
        }

        ListNode* temp2 = temp -> next;
        temp -> next = temp -> next -> next;
        delete temp2;

        return dummy -> next;
    }

    ListNode* solve2(ListNode* head, int n){
        ListNode* dummy = new ListNode(0);
        dummy -> next = head;
        ListNode* slow = dummy;
        ListNode* fast = dummy;

        int cnt = 0;

        while(cnt <= n){
            fast = fast -> next;
            cnt++;
        }

        while(fast != NULL){
            fast = fast -> next;
            slow = slow -> next;
        }

        slow -> next = slow -> next -> next;

        return dummy -> next;
    }

    int cntNodeFromEnd(ListNode* &head, int n){
        if(head == NULL){
            return 0;
        }

        int cnt = cntNodeFromEnd(head -> next, n) + 1;

        if(cnt == n){
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }

        return cnt;
    }

    ListNode* solve3(ListNode* head, int n){
        int cnt = cntNodeFromEnd(head, n);
        return head;
    }
};

