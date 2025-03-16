#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string s;
	cin >> s;

	vector<string> week = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };
	int index = -1;
	for (int i = 0; i < week.size(); i++) {
		if (s == week[i]) {
			index = i;
			break;
		}
	}

	cout << 7 - index << endl;

	return 0;
}

