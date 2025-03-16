
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// Reads a single integer from standard input.
int nextInt() {
	int num;
	cin >> num;
	return num;
}

// Reads a slice of integers from standard input.
vector<int> scanNums(int len) {
	vector<int> nums;
	for (int i = 0; i < len; i++) {
		int num;
		cin >> num;
		nums.push_back(num);
	}
	return nums;
}

// Computes a value using the first two and last two elements of the input slice.
int pattern1(vector<int> l) {
	int n = (l[0]*l[3])+(l[1]*l[4]);
	return n;
}

// Computes another value using the third element and the maximum of the last two elements.
int pattern2(vector<int> l) {
	int n =2*l[2]*max(l[3],l[4]);
	return n;
}

// Computes yet another value using the third element, the minimum of the last two elements, and the result of doch(l).
int pattern3(vector<int> l) {
	int n = 2*l[2]*min(l[3],l[4])+(doch(l));
	return n;
}

// Returns the minimum value among the given integers.
int min(vector<int> nums) {
	if (nums.empty()) {
		cerr << "function min() requires at least one argument." << endl;
		exit(1);
	}
	int res = nums[0];
	for (int i = 0; i < nums.size(); i++) {
		res = min(res, nums[i]);
	}
	return res;
}

// Returns the maximum value among the given integers.
int max(vector<int> nums) {
	if (nums.empty()) {
		cerr << "function max() requires at least one argument." << endl;
		exit(1);
	}
	int res = nums[0];
	for (int i = 0; i < nums.size(); i++) {
		res = max(res, nums[i]);
	}
	return res;
}

// Calculates a specific value based on the input slice.
int doch(vector<int> l) {
	if (l[3]>l[4]) {
		return l[0] * (l[3]-l[4]);
	}else{
		return l[1] * (l[4]-l[3]);
	}
}

// Main function to read input, compute the minimum value, and print it.
int main() {
	int len = 5;
	vector<int> l = scanNums(len);
	cout << min({pattern1(l),pattern2(l), pattern3(l)}) << endl;
}

