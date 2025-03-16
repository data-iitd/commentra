
#include <iostream>

using namespace std;

string group(int n) {
	if (n == 4 || n == 6 || n == 9 || n == 11) {
		return "B";
	} else {
		return "A";
	}
}

int main() {
	int x, y;
	cin >> x >> y;

	if (x == 2 || y == 2) {
		cout << "No" << endl;
		return 0;
	}

	string xg = group(x);
	string yg = group(y);

	if (xg == yg) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}

	return 0;
}

