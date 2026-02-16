/*
Method 1: Iterative
Dummy node is used to simplify head handling.
When one list becomes NULL, directly attach the remaining list:
- If h1 == NULL → temp->next = h2
- If h2 == NULL → temp->next = h1


*/
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // return solve1(list1, list2);
        return solve2(list1, list2);
    }

private:
    ListNode* solve1(ListNode* h1, ListNode* h2){
        if(h1  == NULL){
            return h2;
        }

        if(h2  == NULL){
            return h1;
        }

        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;

        while(h1 != NULL && h2 != NULL){
            if(h1 -> val <= h2 -> val){
                temp -> next = h1;
                temp = h1;
                h1 = h1 -> next;
            }else{
                temp -> next = h2;
                temp = h2;
                h2 = h2 -> next;
            }
        }

        if(h1 != NULL){
            temp -> next = h1;
        }

        if(h2 != NULL){
            temp -> next = h2;
        }

        return dummy -> next;
    }

    ListNode* solve2(ListNode* h1, ListNode* h2){
        if(h1 == NULL){
            return h2;
        }

        if(h2 == NULL){
            return h1;
        }

        ListNode* finalHead = NULL;

        if(h1 -> val <= h2 -> val){
            h1 -> next = solve2(h1 -> next, h2);
            finalHead = h1;
        }else{
            h2 -> next = solve2(h1, h2 -> next);
            finalHead = h2;
        }

        return finalHead;
    }
};

