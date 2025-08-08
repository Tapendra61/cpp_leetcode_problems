#include<iostream>
#include"problems.h"

int main() {
	vector<int> asteroids = {-2, -1, 1, 2};

	vector<int> result = asteroidCollision(asteroids);

	for (int asteroid : result) {
		print("{}", asteroid);
	}

	return 0;
}