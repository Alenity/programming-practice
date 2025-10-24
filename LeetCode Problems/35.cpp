#include <cstdio>
#include <vector>



using std::vector;
class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		int lower = 0;
		int upper = nums.size()-1;
		int middle = (nums.size()-1)/2;

		return middle;
	}	
};




int main(int argc, char** argv) {

	vector<int> numbers = {0, 1, 2, 4, 5, 5, 6};
	int number = 4;
	Solution sol;
	printf("%d", sol.searchInsert(numbers, number));
	return 0;
}