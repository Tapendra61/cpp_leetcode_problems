#include<iostream>
#include"problems.h"

int main() {
	vector<int> nums = {3, 3, 2, 4, 3, 5};
	
	bool result = containsDuplicate(nums);


	cout << result << endl;

	return 0;
}