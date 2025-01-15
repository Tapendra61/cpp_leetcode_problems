#include<iostream>
#include"problems.h"

using namespace std;

int main() {
	vector<int> nums = {1, 3, 5, 6};
	vector<int> resultIndexes;
	int target = 4;

	resultIndexes = twoSum(nums, target);

	for (int num : resultIndexes) {
		cout << num << endl;
	}

	return 0;
}