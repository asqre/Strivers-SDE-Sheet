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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // return solve1(headA, headB);
        // return solve2(headA, headB);
        // return solve3(headA, headB);
        return solve4(headA, headB);
    }
private:
    // Optimal Approach in O(m + n) without finding the length
    ListNode* solve4(ListNode* h1, ListNode* h2){
        ListNode* t1 = h1;
        ListNode* t2 = h2;

        while(t1 != t2){
            t1 = t1 == NULL ? h2 : t1 = t1 -> next;
            t2 = t2 == NULL ? h1 : t2 = t2 -> next;
        }

        return t1;
    }

    // Brute Force
    ListNode* solve1(ListNode* h1, ListNode* h2){
        ListNode* t1 = h1;
        ListNode* t2 = h2;
        
        while(t1 != NULL){
            while(t2 != NULL){
                if(t1 == t2){
                    return t1;
                }

                t2 = t2 -> next;
            }

            t1 = t1 -> next;
            t2 = h2;
        }

        return NULL;
    }

    // Using Set or hash
    ListNode* solve2(ListNode* h1, ListNode* h2){
        unordered_set<ListNode*> st;

        ListNode* temp1 = h1;
        ListNode* temp2 = h2;

        while(temp1 != NULL){
            st.insert(temp1);
            temp1 = temp1 -> next;
        }

        while(temp2 != NULL){
            if(st.find(temp2) != st.end()){
                return temp2;
            }
            temp2 = temp2 -> next;
        }

        return NULL;
    }

    // Optimal approach using two pointer
    ListNode* solve3(ListNode* h1, ListNode* h2){
        int len1 = len(h1);
        int len2 = len(h2);

        if(len1 > len2){
            return intersectionNode(h2, h1, len1 - len2);
        }else{
            return intersectionNode(h1, h2, len2 - len1);
        }
    }

    ListNode* intersectionNode(ListNode* h1, ListNode* h2, int diff){
        while(diff > 0){
            h2 = h2 -> next;
            diff--;
        }

        while(h1 != NULL){
            if(h1 == h2){
                return h1;
            }

            h1 = h1 -> next;
            h2 = h2 -> next;
        }

        return NULL;
    }

    int len(ListNode* head){
        if(head == NULL){
            return 0;
        }

        return 1 + len(head -> next);
    }
};