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
	ListNode* min(ListNode* one, ListNode* two) {
		if (one != nullptr && two != nullptr) {
			if (one->val <= two->val) {
				return one;
			} else {
				return two;
			}
		} else if (one) {
			return one;
		} else if (two) {
			return two;
		} else {
			return nullptr;
		}
		
	};



	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
		using NodePtr = ListNode*;
		NodePtr curr1, curr2, prev, newHead;
		if (min(list1, list2) == nullptr) {return nullptr;}
		newHead, prev = min(list1, list2);
		curr1 = list1;
		curr2 = list2;
		while (curr1 != nullptr && curr2 != nullptr) {
			if (min(curr1, curr2) == curr1) {
				curr1 = curr1->next;
			} else {
				curr2 = curr2->next;
			}	
			prev->next = min(curr1, curr2);
			prev = prev->next;
		}
		return newHead;
	};
};