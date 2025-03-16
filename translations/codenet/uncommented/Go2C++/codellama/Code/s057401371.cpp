#include <iostream>
#include <string>

using namespace std;

int main() {
	string s;
	cin >> s;

	int d = 'a' - 'A';
	for (int i = 0; i < s.size(); i++) {
		char r = s[i];
		if ('A' <= r && r <= 'Z') {
			r += d;
		} else if ('a' <= r && r <= 'z') {
			r -= d;
		}
		cout << r;
	}
	cout << endl;
	return 0;
}

