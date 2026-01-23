#include <cstdio>
#include <vector>


// Submission #1
using std::vector;
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() > 1) {
			int uniques = 1;
			for (int i = 1; i < nums.size(); i++) {
				if (nums[i-1] == nums[i]) {
			    	nums.erase(nums.begin()+i);
			    	i--;
				} else {
					uniques++;
				}
	        }
	        return uniques;
		} else if (nums.size() == 1) {
			return 1;
		} else {
			return 0;
		}
    }
};


int main(int argc, char** argv) {

	return 1;
};