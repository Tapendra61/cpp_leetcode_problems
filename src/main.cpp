#include<iostream>
#include"problems.h"

int main() {
	vector<int> nums = {0, 1, 0, 3, 12};

	moveZeroes(nums);

	for (int num : nums) {
		cout << num << ", ";
	}

	return 0;
}