/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // using hash Map
        // return solve1(head);

        // By inserting copied node between two original node
        return solve2(head);
    }

private:
    Node* solve2(Node* head){
        Node* temp = head;

        // Step-1: Insert copied node between original nodes
        while(temp != NULL){
            Node* newNode = new Node(temp -> val);
            newNode -> next = temp -> next;
            temp -> next = newNode;
            temp = temp -> next -> next;
        }

        // Step-2: Assign random pointers
        temp = head;
        while(temp != NULL){
            if(temp -> random != NULL){
                temp -> next -> random = temp -> random -> next;
            }
            temp = temp -> next -> next;
        }

        // Step-3: Separate original and copied list
        temp = head;
        Node* dummy = new Node(0);
        Node* temp2 = dummy;
        
        while(temp != NULL){
            temp2  -> next = temp -> next;
            temp2 = temp2 -> next;
            temp -> next = temp2 -> next;
            temp = temp -> next;
        }

        return dummy -> next;
    }

    // using Hash map
    Node* solve1(Node* head){
        Node* temp = head;
        Node* dummy = new Node(0);
        Node* copyTemp = dummy;

        // map that store [originalNode = copiedNode]
        unordered_map<Node*, Node*> m;

        while(temp != NULL){
            Node* newNode = new Node(temp -> val);
            m[temp] = newNode;
            copyTemp -> next = newNode;
            copyTemp = newNode;
            temp = temp -> next;
        }

        temp = head;
        copyTemp = dummy -> next;

        while(temp != NULL){
            copyTemp -> random = m[temp->random];
            temp = temp -> next;
            copyTemp = copyTemp -> next;
        }

        return dummy -> next;
    }
};