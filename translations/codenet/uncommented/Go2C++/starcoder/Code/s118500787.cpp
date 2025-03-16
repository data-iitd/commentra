#include <bits/stdc++.h>

using namespace std;

int main() {
	string S, T;
	cin >> S >> T;
	int max = 0;
	for (int i = 0; i <= S.size() - T.size(); i++) {
		int c = 0;
		for (int j = 0; j < T.size(); j++) {
			if (S[i + j] == T[j]) {
				c++;
			}
		}
		if (max < c) {
			max = c;
		}
	}
	cout << T.size() - max << endl;
}

