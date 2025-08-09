#pragma once

#include<print>
#include<vector>
#include<unordered_set>
#include<string>
#include<stack>

using namespace std;

vector<int> twoSum(vector<int> &nums, int target);
bool isPalindrome(int num);
int removeElement(vector<int> &nums, int val);
bool containsDuplicate(vector<int> &nums);
string mergeAlternately(string word1, string word2);
vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies);
bool canPlaceFlowers(vector<int> &flowerbed, int n);
void moveZeroes(vector<int> &nums);
//vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2);
string longestCommonPrefix(vector<string>& strs);
int pivotIndex(vector<int>& nums);
string removeStars(string s);
vector<int> asteroidCollision(vector<int>& asteroids);
string reverseVowels(string s);