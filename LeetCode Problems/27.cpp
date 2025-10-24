#include <cstdio>

class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		int vals = 0;
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] == val) {
				vals++
			} else {
				nums[i-vals] = nums[i];
			}
		}
		return nums.size()-vals;
	}
}


int main(int argc, char** argv) {
	return 1;
}