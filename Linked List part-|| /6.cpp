/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 * 		Node *child;
 *		Node() : data(0), next(nullptr), child(nullptr){};
 *		Node(int x) : data(x), next(nullptr), child(nullptr) {}
 *		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
 * };
 */
#include <algorithm>
// Using Array ============================
vector<int> convertLLtoArr(Node* head){
	Node* temp = head;
	vector<int> ans;

	while(temp != NULL){
		Node* tempChild = temp;

		while(tempChild != NULL){
			ans.push_back(tempChild -> data);
			tempChild = tempChild -> child;
		}

		temp = temp -> next;
	}

	return ans;
}

Node* solve1(Node* head){
	vector<int> nums = convertLLtoArr(head);

	sort(nums.begin(), nums.end());

	Node* dummy = new Node(0);
	Node* temp = dummy;

	for(auto num : nums){
		Node* newNode = new Node(num);
		temp -> child = newNode;
		temp = newNode;
	}

	temp -> child = NULL;

	return dummy -> child;
}


// using Merging two list at a time ===============
Node* mergeTwoList(Node* list1, Node* list2){
	Node* dummy = new Node(0);
	Node* temp = dummy;

	while(list1 != NULL &&  list2 != NULL){
		if(list1 -> data <= list2 -> data){
			temp -> child = list1;
			list1 = list1 -> child;
		}else{
			temp -> child = list2;
			list2 = list2 -> child;
		}

		temp = temp -> child;
	}

	if(list1 != NULL){
		temp -> child = list1;
	}else{
		temp -> child = list2;
	}

	return dummy -> child;
}

Node* solve2(Node* head){
	if(head == NULL || head -> next == NULL){
		return head;
	}

	Node* currList = head;
	Node* nextList = head -> next;

	while(nextList != NULL){
		currList = mergeTwoList(currList, nextList);
		nextList = nextList -> next;
	}

	return currList;
}

Node* flattenLinkedList(Node* head) 
{
	// Write your code here
	// using Array
	// return solve1(head);

	// using Merging two list at a time
	return solve2(head);

}


