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

//Remove Element
int removeElement(vector<int> &nums, int val) {
	int k = 0;
	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] != val) {
			nums[k++] = nums[i];
		}
	}

	return k;
}

//Contains Duplicate
bool containsDuplicate(vector<int> &nums) {
	std::unordered_set<int> seen;
	for (const int num: nums) {
		if (seen.count(num)) {
			return true;
		}
		seen.insert(num);
	}
	
	return false;
}

//Merge Strings Alternately
string mergeAlternately(string word1, string word2) {
	string mergedString;
	mergedString.reserve(word1.size() + word2.size());

	int minSize = word1.size() < word2.size() ? word1.size() : word2.size();
	for (int i = 0; i < minSize; i++) {
		mergedString.push_back(word1[i]);
		mergedString.push_back(word2[i]);
	}

	for (int i = minSize; i < word1.size(); i++) {
		mergedString.push_back(word1[i]);
	}

	for (int i = minSize; i < word2.size(); i++) {
		mergedString.push_back(word2[i]);
	}

	return mergedString;
}

//Kids With Greatest Number Of Candies
vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
	int max = 0;
	vector<bool> result;
	result.reserve(candies.size());

	for (int i = 0; i < candies.size(); i++) {
		if (candies[i] > max) {
			max = candies[i];
		}
	}

	for (int i = 0; i < candies.size(); i++) {
		if (candies[i] + extraCandies >= max) {
			result.push_back(true);
			continue;
		}
		result.push_back(false);
	}

	return result;
}

//Can Place Flowers
bool canPlaceFlowers(vector<int> &flowerbed, int n) {
	int flowersPlaced = 0;

	for (int i = 0; i < flowerbed.size(); i++) {
		if (flowerbed[i] == 0) {
			bool leftCheck = (i == 0 || flowerbed[i - 1] == 0);
			bool rightCheck = (i == flowerbed.size() - 1 || flowerbed[i + 1] == 0);

			if (leftCheck && rightCheck) {
				flowersPlaced++;
				flowerbed[i] = 1;
			}
		}
	}

	return flowersPlaced >= n;
}

//Move Zeroes
void moveZeroes(vector<int>& nums) {
	int nonZeroIndex = 0;

	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] != 0) {
			nums[nonZeroIndex] = nums[i];
			nonZeroIndex++;
		}
	}

	for (int i = nonZeroIndex; i < nums.size(); i++) {
		nums[i] = 0;
	}
}

//Find the Difference of Two Arrays
vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {

}

//Longest Common Prefix
string longestCommonPrefix(vector<string>& strs) {
	if (strs.empty()) return "";

	string commonPrefix = "";
	string smallest = "";
	
	smallest = strs[0];
	for (string& str : strs) {
		if (str.size() < smallest.size()) {
			smallest = str;
		}
	}

	for (int i = 0; i < smallest.size(); i++) {
		char currentChar = smallest[i];
		for (const string& str : strs) {
			if (str[i] != currentChar) {
				return commonPrefix;
			}
		}

		commonPrefix += currentChar;
	}

	return commonPrefix;
}

//Find Pivot Index
int pivotIndex(vector<int> nums) {
	int index = -1;
	for (int i = 0; i < nums.size(); i++) {
		int leftSum = 0;
		int rightSum = 0;
		for (int j = 0; j < i; j++) {
			leftSum += nums[j];
		}

		for (int j = i + 1; j < nums.size(); j++) {
			rightSum += nums[j];
		}

		if (leftSum == rightSum) return i;

	}
	return index;
}