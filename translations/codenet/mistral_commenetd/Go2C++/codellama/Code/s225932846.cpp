
#include <iostream>
#include <string>

using namespace std;

int main() {
	string S;
	cin >> S;
	int i = 2;
	while (i <= S.length()) {
		if (S.substr(0, (S.length() - i) / 2) == S.substr((S.length() - i) / 2, S.length() - i)) {
			cout << (S.length() - i) << endl;
			break;
		}
		i += 2;
	}
	return 0;
}

