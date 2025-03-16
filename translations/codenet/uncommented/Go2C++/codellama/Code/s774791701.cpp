#include <iostream>

using namespace std;

int main() {
	string s;
	cin >> s;

	int price = 700;
	for (char c : s) {
		if (c == 'o') {
			price += 100;
		}
	}
	cout << price << endl;

	return 0;
}

