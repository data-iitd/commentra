
#include <iostream>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

const int initialBufSize = 10000;
const int maxBufSize = 1000000;

int mod = 1e9 + 7;

int getInt() {
	int i;
	cin >> i;
	return i;
}

string getString() {
	string s;
	cin >> s;
	return s;
}

int abs(int a) {
	return abs(a);
}

int pow(int p, int q) {
	return pow(p, q);
}

int min(int nums) {
	int res = nums;
	for (int i = 0; i < nums; i++) {
		res = min(res, nums[i]);
	}
	return res;
}

int max(int nums) {
	int res = nums;
	for (int i = 0; i < nums; i++) {
		res = max(res, nums[i]);
	}
	return res;
}

bool strSearch(vector<string> a, string b) {
	for (int i = 0; i < a.size(); i++) {
		if (a[i] == b) {
			return true;
		}
	}
	return false;
}

void printIntArray(vector<int> array) {
	string strArray = to_string(array);
	cout << strArray.substr(1, strArray.size() - 2) << endl;
}

int calcMod(int x) {
	return x % mod;
}

int main() {
	vector<string> week = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };
	string s = getString(); // Get the input day as a string.
	int index = -1;
	for (int i = 0; i < week.size(); i++) {
		if (s == week[i]) {
			index = i; // Set the index of the day found in the week array.
			break;
		}
	}

	cout << 7 - index << endl; // Print the number of days until Sunday.
}

