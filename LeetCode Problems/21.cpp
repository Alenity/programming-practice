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
		} else if (one != nullptr) {
			return one;
		} else if (two != nullptr) {
			return two;
		} else {
			return nullptr;
		}
	};



	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
		using NodePtr = ListNode*;
		NodePtr curr1 = nullptr, curr2 = nullptr, prev = nullptr, newHead = nullptr;
		newHead = prev = lesser(list1, list2);
		curr1 = list1;
		curr2 = list2;
		printf("nullptr = %p\n", (void*)nullptr);
		while (curr1 != nullptr || curr2 != nullptr) {
			if (lesser(curr1, curr2) == curr1) {
				curr1 = curr1->next;
			} else if (lesser(curr1, curr2) == curr2) {
				curr2 = curr2->next;
			} else {
				break;
			}
			prev->next = lesser(curr1, curr2);
			prev = prev->next;
			printf("curr1 = %p, two = %p\n", (void*)curr1, (void*)curr2);
		}
		return newHead;
	};


	ListNode* mergeTwoListsBetter(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;

        while (list1 && list2) {
            if (list1->val > list2->val) {
                cur->next = list2;
                list2 = list2->next;
            } else {
                cur->next = list1;
                list1 = list1->next;
            }
            cur = cur->next;
        }

        cur->next = list1 ? list1 : list2;

        return dummy->next;        
    }
};



int main() {
	return 0;
}