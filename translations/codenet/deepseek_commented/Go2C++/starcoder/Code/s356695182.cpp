#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int len = 5;
	vector<int> l = {0,0,0,0,0};
	for (int i = 0; i < len; i++) {
		cin >> l[i];
	}
	int res = min(pattern1(l), pattern2(l), pattern3(l));
	cout << res << endl;
}

int pattern1(vector<int> l) {
	int n = (l[0]*l[3])+(l[1]*l[4]);
	return n;
}

int pattern2(vector<int> l) {
	int n = 2*l[2]*max(l[3],l[4]);
	return n;
}

int pattern3(vector<int> l) {
	int n = 2*l[2]*min(l[3],l[4])+(doch(l));
	return n;
}

int min(int a, int b) {
	return a < b? a : b;
}

int max(int a, int b) {
	return a > b? a : b;
}

int doch(vector<int> l) {
	if (l[3] > l[4]) {
		return l[0] * (l[3] - l[4]);
	} else {
		return l[1] * (l[4] - l[3]);
	}
}

