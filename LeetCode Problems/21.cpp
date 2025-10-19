#include <cstdio>

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
}

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
		ListNode* curr1, curr2;
		curr1 = list1;
		curr2 = list2;
		while (curr1.next != nullptr && curr2.next != nullptr) {
			if (curr1.val )
		}
	}
}