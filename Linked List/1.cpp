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
    ListNode* reverseList(ListNode* head) {
        // return solve1(head);
        // return solve2(head);
        return solve3(head);
    }

private:
    ListNode* solve3(ListNode* head){
        if(head == NULL){
            return head;
        }

        ListNode* temp = head;

        stack<ListNode*> st;

        while(temp != NULL){
            st.push(temp);
            temp = temp -> next;
        }

        ListNode* newHead = NULL;
        
        while(!st.empty()){
            if(newHead == NULL){
                newHead = st.top();
                temp = newHead;
            }else{
                temp -> next = st.top();
                temp = temp -> next;
            }
            st.pop();
        }

        temp -> next = NULL;

        return newHead;

    }

    ListNode* solve2(ListNode* head){
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

    ListNode* solve1(ListNode* head){
        if(head == NULL || head -> next == NULL){
            return head;
        }

        ListNode* newHead = solve1(head -> next);
    
        head -> next -> next = head;
        head -> next = NULL;

        return newHead;
    }
};
