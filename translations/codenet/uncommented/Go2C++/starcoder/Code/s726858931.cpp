#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string s;
	cin >> s;

	char c = 'a';

	for (int j = 0; j < 26; j++) {
		bool found = false;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == c) {
				found = true;
				break;
			}
		}
		if (found == false) {
			cout << c << endl;
			return 0;
		}
		c++;
	}

	cout << "None" << endl;

	return 0;
}

