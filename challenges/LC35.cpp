#include <cstdio>
#include <vector>



using std::vector;
class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		int lower = 0;
		int upper = nums.size()-1;
		int middle = (nums.size()-1)/2;
		if (nums.size() == 0) {
			
		}
		return middle;
	}	
};



int main(int argc, char** argv) {
	return 0;
}