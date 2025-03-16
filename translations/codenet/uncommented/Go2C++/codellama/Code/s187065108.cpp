
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int scanInt() {
	int num;
	cin >> num;
	return num;
}

string scanString() {
	string str;
	cin >> str;
	return str;
}

vector<int> scanInts(int n) {
	vector<int> sl(n);
	for (int i = 0; i < n; i++) {
		sl[i] = scanInt();
	}
	return sl;
}

vector<string> scanStrings(int n) {
	vector<string> sl(n);
	for (int i = 0; i < n; i++) {
		sl[i] = scanString();
	}
	return sl;
}

int main() {
	int r, D, x;
	r = scanInt();
	D = scanInt();
	x = scanInt();
	for (int i = 1; i <= 10; i++) {
		x = r*x - D;
		cout << x << endl;
	}
	return 0;
}

