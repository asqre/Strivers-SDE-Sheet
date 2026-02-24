class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // return solve1(l1, l2);
        return solve2(l1, l2);
    }

private:
    // Reduce Repeatation
    ListNode* solve2(ListNode* l1, ListNode* l2){
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;

        int sum = 0;
        int carry = 0;

        while(l1 != NULL || l2 != NULL || carry != 0){
            sum = carry;

            if(l1 != NULL){
                sum += l1 -> val;
                l1 = l1 -> next;
            }

            if(l2 != NULL){
                sum += l2 -> val;
                l2 = l2 -> next;
            }

            carry = sum / 10;

            int data = sum % 10;
            ListNode* newNode = new ListNode(data);

            temp -> next  = newNode;
            temp = newNode;
        }

        temp -> next = NULL;

        return dummy -> next;
    }

    ListNode* solve1(ListNode* l1, ListNode* l2){
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;

        int sum = 0;
        int carry = 0;

        while(l1 != NULL && l2 != NULL){
            sum = (l1 -> val) + (l2 -> val) + carry;
            carry = sum / 10;

            int data = sum % 10;
            ListNode* newNode = new ListNode(data);

            temp -> next  = newNode;
            temp = newNode;

            l1 = l1 -> next;
            l2 = l2 -> next;
        }

        while(l1 != NULL){
            sum = (l1 -> val) + carry;
            carry = sum / 10;

            int data = sum % 10;
            ListNode* newNode = new ListNode(data);

            temp -> next  = newNode;
            temp = newNode;

            l1 = l1 -> next;
        }

        while(l2 != NULL){
            sum = (l2 -> val) + carry;
            carry = sum / 10;

            int data = sum % 10;
            ListNode* newNode = new ListNode(data);

            temp -> next  = newNode;
            temp = newNode;

            l2 = l2 -> next;
        }

        if(carry != 0){
            int data = carry;
            ListNode* newNode = new ListNode(data);

            temp -> next  = newNode;
            temp = newNode;
        }

        temp -> next = NULL;

        return dummy -> next;
    }
};