#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	string S;
	cin >> S;
	if (S.substr(0, 4) == "YAKI") {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
}

