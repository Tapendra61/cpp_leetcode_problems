#include<iostream>
#include"problems.h"

int main() {
	vector<int> nums = {3, 3, 2, 4, 3, 5};
	int val = 3;
	int result = removeElement(nums, val);


	cout << result << endl;

	return 0;
}