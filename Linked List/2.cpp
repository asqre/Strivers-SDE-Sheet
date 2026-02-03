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
    ListNode* middleNode(ListNode* head) {
        // return solve1(head);
        return solve2(head);
    }

private:
    int findLength(ListNode* head){
        if(head == NULL){
            return 0;
        }

        return 1 + findLength(head -> next);
    }

    ListNode* kthElement(ListNode* head, int k){
        ListNode* temp = head;

        while(k != 1){
            temp = temp -> next;
            k--;
        }

        return temp;
    }


    ListNode* solve1(ListNode* head){
        int len = findLength(head);

        int m = (len + 1) >> 1;

        ListNode* ans = NULL;

        if(len % 2 == 0){
            ans = kthElement(head, m + 1);
        }else{
            ans = kthElement(head, m);
        }

        return ans;
    }

    ListNode* solve2(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast -> next != NULL){
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        return slow;
    }
};