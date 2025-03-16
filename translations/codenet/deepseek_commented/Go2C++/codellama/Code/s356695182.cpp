
#include <iostream>
#include <cmath>

using namespace std;

int min(int nums[], int len) {
	int res = nums[0];
	for (int i = 0; i < len; i++) {
		res = min(res, nums[i]);
	}
	return res;
}

int max(int nums[], int len) {
	int res = nums[0];
	for (int i = 0; i < len; i++) {
		res = max(res, nums[i]);
	}
	return res;
}

int doch(int l[]) {
	if (l[3] > l[4]) {
		return l[0] * (l[3] - l[4]);
	} else {
		return l[1] * (l[4] - l[3]);
	}
}

int pattern1(int l[]) {
	int n = (l[0] * l[3]) + (l[1] * l[4]);
	return n;
}

int pattern2(int l[]) {
	int n = 2 * l[2] * max(l[3], l[4]);
	return n;
}

int pattern3(int l[]) {
	int n = 2 * l[2] * min(l[3], l[4]) + (doch(l));
	return n;
}

int main() {
	int len = 5;
	int l[len];
	for (int i = 0; i < len; i++) {
		cin >> l[i];
	}
	cout << min(pattern1(l), pattern2(l), pattern3(l)) << endl;
	return 0;
}

