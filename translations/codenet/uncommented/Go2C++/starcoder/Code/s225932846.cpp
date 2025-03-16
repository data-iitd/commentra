#include <iostream>
#include <string>

using namespace std;

int main() {
	string S;
	cin >> S;
	for (int i = 2; i <= S.length(); i = i + 2) {
		if (S.substr(0, S.length() - i / 2) == S.substr(S.length() - i / 2, S.length() - i)) {
			cout << S.length() - i << endl;
			break;
		}
	}
	return 0;
}

