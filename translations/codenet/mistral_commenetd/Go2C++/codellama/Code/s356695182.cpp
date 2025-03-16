
#include <iostream>
#include <cmath>

using namespace std;

// Function to read an integer from standard input
int nextInt() {
	int t;
	cin >> t;
	return t;
}

// Function to read multiple integers from standard input
int* scanNums(int len) {
	int* nums = new int[len];
	for (int i = 0; i < len; i++) {
		cin >> nums[i];
	}
	return nums;
}

// Function to calculate the first pattern
int pattern1(int* l) {
	int n = (l[0]*l[3])+(l[1]*l[4]);
	return n;
}

// Function to calculate the second pattern
int pattern2(int* l) {
	int maxNum = max(l[3], l[4]);
	int n = 2 * l[2] * maxNum;
	return n;
}

// Function to calculate the third pattern
int pattern3(int* l) {
	int minNum = min(l[3], l[4]);
	int n = 2 * l[2] * minNum + doch(l);
	return n;
}

// Function to find the minimum of a list of numbers
int min(int nums[], int len) {
	int res = nums[0];
	for (int i = 0; i < len; i++) {
		res = min(res, nums[i]);
	}
	return res;
}

// Function to find the maximum of a list of numbers
int max(int nums[], int len) {
	int res = nums[0];
	for (int i = 0; i < len; i++) {
		res = max(res, nums[i]);
	}
	return res;
}

// Helper function to calculate the difference between the larger and smaller of two numbers
int doch(int* l) {
	if (l[3] > l[4]) {
		return l[0] * (l[3] - l[4]);
	} else {
		return l[1] * (l[4] - l[3]);
	}
}

// Main function to read input and call the pattern functions
int main() {
	int len = 5;
	int* l = scanNums(len);
	cout << min(pattern1(l), pattern2(l), pattern3(l)) << endl;
	return 0;
}

