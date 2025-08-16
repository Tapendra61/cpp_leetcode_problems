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
//vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
//
//}

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
int pivotIndex(vector<int>& nums) {
	int totalSum = 0, leftSum = 0;

	for (int num : nums) totalSum += num;

	for (int i = 0; i < nums.size(); i++) {
		if (leftSum == totalSum - leftSum - nums[i]) return i;
		leftSum += nums[i];
	}

	return -1;
}

//Removing Stars From a String
string removeStars(string s) {
	stack<char> st;

	for (char c : s) {
		if (c == '*') {
			if (!st.empty()) {
				st.pop();
			}
			continue;
		}

		st.push(c);
	}

	string result;
	result.resize(st.size());
	size_t back = result.size() - 1;

	while (!st.empty()) {
		result[back--] = st.top();
		st.pop();
	}

	return result;
}

//Asteroid Collision
vector<int> asteroidCollision(vector<int>& asteroids) {
	stack<int> asteroidStack;

	for (int asteroid : asteroids) {
		bool destroyed = false;

		while (!asteroidStack.empty() && asteroidStack.top() > 0 && asteroid < 0) {
			if (asteroidStack.top() < -asteroid) {
				asteroidStack.pop();
				continue;
			}
			else if (asteroidStack.top() == -asteroid) {
				asteroidStack.pop();
				destroyed = true;
				break;
			}
			else {
				destroyed = true;
				break;
			}
		}

		if (!destroyed) {
			asteroidStack.push(asteroid);
		}
	}

	vector<int> remainingAsteroids;
	remainingAsteroids.resize(asteroidStack.size());

	for (int i = asteroidStack.size() - 1; i >= 0; --i) {
		remainingAsteroids[i] = asteroidStack.top();
		asteroidStack.pop();
	}

	return remainingAsteroids;
}

// Reverse Vowels of a String
string reverseVowels(string s) {

	int i = 0, j = s.length() - 1;

	while (i < j) {
		if (!isVowel(s[i])) { ++i; continue; }
		if (!isVowel(s[j])) { --j; continue; }
		swap(s[i], s[j]);
		++i;
		--j;
	}

	return s;
}

// Find the Highest Altitude
int largestAltitude(vector<int>& gain) {
	int highest = 0;
	int sum = 0;

	for (int i = 0; i < gain.size() - 1; i++) {
		sum = sum + gain[i];
		if (sum > highest) highest = sum;
	}
	return highest;
}