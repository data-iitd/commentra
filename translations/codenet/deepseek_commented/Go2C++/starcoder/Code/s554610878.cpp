#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int week[7] = { 0, 1, 2, 3, 4, 5, 6 };
	string s;
	cin >> s;
	int index = -1;
	for (int i = 0; i < 7; i++) {
		if (s == week[i]) {
			index = i;
			break;
		}
	}

	cout << 7 - index << endl;
	return 0;
}

