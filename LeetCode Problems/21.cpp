#include <cstdio>

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
		using NodePtr = ListNode*;
		NodePtr curr1, curr2, temp1, temp2, newHead;
		if (!list1 && list2) {
			return list2;
		} else if (list1 && !list2) {
			return list1;e
		} else if (!list1 && !list2) {
			return newHead;
		}
		curr1 = list1;
		curr2 = list2;
		if (curr1->val <= curr2->val) {
			newHead = curr1;
		} else { 
			newHead = curr2;
		}
		while (curr1->next != nullptr && curr2->next != nullptr) {
			if (curr1->val <= curr2->val) {
				temp1 = curr1->next;
				temp2 = curr2->next;
				curr1->next = curr2;
				curr2->next = temp1;
				curr1 = temp1;
				curr2 = temp2;
			} else {
				temp1 = curr2->next;
				temp2 = curr1->next;
				curr2->next = curr1;
				curr1->next = temp1;
				curr2 = temp1;
				curr1 = temp2;
			}
		}

		return newHead;
	}
};