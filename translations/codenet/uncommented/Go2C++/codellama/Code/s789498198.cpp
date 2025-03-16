
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

struct Pair {
	int first;
	int second;
};

struct Queue {
	vector<Pair> v;

	void Push(Pair v) {
		this->v.push_back(v);
	}

	Pair Pop() {
		Pair r = this->v[0];
		this->v.erase(this->v.begin());
		return r;
	}

	Pair Front() {
		return this->v[0];
	}

	bool Empty() {
		return this->v.size() == 0;
	}
};

int digits(int x) {
	return to_string(x).length();
}

int powInt(int x, int p) {
	int result = 1;
	for (int i = 0; i < p; i++) {
		result *= x;
	}
	return result;
}

int max(int x, int y) {
	return x > y ? x : y;
}

int min(int x, int y) {
	return x < y ? x : y;
}

int abs(int x) {
	return x < 0 ? -x : x;
}

void varDump(int value) {
	cout << value << endl;
}

void yes() {
	cout << "Yes" << endl;
}

void no() {
	cout << "No" << endl;
}

int main() {
	int AB[2];
	cin >> AB[0] >> AB[1];
	int A = AB[0];
	int B = AB[1];

	if ((A + B) % 2 == 0) {
		cout << (A + B) / 2 << endl;
		return 0;
	}
	cout << "IMPOSSIBLE" << endl;
	return 0;
}

