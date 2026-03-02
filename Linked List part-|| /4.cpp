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
    bool isPalindrome(ListNode* head) {
        // return solve1(head);
        return solve2(head);
    }

private:
    // using reverse Second Half in place 
    bool solve2(ListNode* head){
        // find mid node
        ListNode* midNode = findMidNode(head);

        // reverse LL from mid node to last
        ListNode* rHead = reverseLL(midNode);

        // Compare rHead with head
        while(rHead != NULL){
            if(head -> val != rHead -> val){
                return false;
            }

            head = head -> next;
            rHead = rHead -> next;
        }

        return true;
    }

    ListNode* findMidNode(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast -> next != NULL && fast -> next -> next != NULL){
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        return slow -> next;
    }

    ListNode* reverseLL(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;

        while(curr != NULL){
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    // Recursive approach
    bool solve1(ListNode* head){
        ListNode* frontPtr = head;

        return compare(head, frontPtr);
    }

    bool compare(ListNode* head, ListNode* &fp){
        if(head == NULL){
            return true;
        }

        bool check = compare(head -> next, fp);

        if(fp -> val != head -> val){
            return false;
        }

        fp = fp -> next;

        return check;
    }
};