
#include <iostream>
#include <string>

using namespace std;

int main() {
	string s;
	cin >> s;
	if (s.length() >= 4 && s.substr(0, 4) == "YAKI") {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
	return 0;
}

