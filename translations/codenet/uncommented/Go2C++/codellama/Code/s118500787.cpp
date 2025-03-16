
#include <iostream>
#include <string>

using namespace std;

int main() {
	string S, T;
	cin >> S >> T;
	int max = 0;
	for (int i = 0; i <= S.length() - T.length(); i++) {
		int c = 0;
		for (int j = 0; j < T.length(); j++) {
			if (S[i+j] == T[j]) {
				c++;
			}
		}
		if (max < c) {
			max = c;
		}
	}
	cout << T.length() - max << endl;
	return 0;
}

