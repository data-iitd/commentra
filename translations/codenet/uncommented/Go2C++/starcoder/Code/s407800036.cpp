#include <iostream>

using namespace std;

int main() {
	// Code for A - Between Two Integers
	int A, B, C;
	cin >> A >> B >> C;

	if (C >= A && C <= B) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
}

