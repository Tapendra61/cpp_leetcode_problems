#include"problems.h"

//Two Sum
vector<int> twoSum(vector<int>& nums, int target) {
	vector<int> resultIndexes;

	for (int i = 0; i < nums.size() - 1; i++) {
		for (int j = i + 1; j < nums.size(); j++) {
			if (nums[i] + nums[j] == target) {
				resultIndexes.push_back(i);
				resultIndexes.push_back(j);
			}
		}
	}

	return resultIndexes;
}

//Palindrome Number
bool isPalindrome(int num) {
	unsigned int result = 0;
	int original = num;

	while (num > 0) {
		result = result * 10 + (num % 10);
		num /= 10;
	}

	return result == original;
}