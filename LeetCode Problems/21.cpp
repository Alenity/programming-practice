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
	ListNode* lesser(ListNode* one, ListNode* two) {
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



	ListNode* mergeTwoLists(ListNode* list1 = nullptr, ListNode* list2 = nullptr) {
		using NodePtr = ListNode*;
		NodePtr curr1, curr2, prev, newHead;
		newHead, prev = lesser(list1, list2);
		curr1 = list1;
		curr2 = list2;
		while (curr1 != nullptr && curr2 != nullptr) {
			if (lesser(curr1, curr2) == curr1) {
				curr1 = curr1->next;
			} else {
				curr2 = curr2->next;
			}
			prev->next = lesser(curr1, curr2);
			prev = prev->next;
			printf("curr1 = %p, two = %p\n", (void*)curr1, (void*)curr2);
		}
		return newHead;
	};
};

int main() {
	return 0;
}