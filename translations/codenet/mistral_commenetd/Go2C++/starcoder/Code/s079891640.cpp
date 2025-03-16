
#include <iostream>
#include <string>

using namespace std;

int main() {
	string s;
	cin >> s;

	for (int i = 0; i < s.length(); i++) {
		if (s.find(s[i], i+1)!= string::npos) {
			cout << "no" << endl;
			return 0;
		}
	}

	cout << "yes" << endl;
	return 0;
}

