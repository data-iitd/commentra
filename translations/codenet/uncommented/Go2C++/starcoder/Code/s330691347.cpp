#include <bits/stdc++.h>

using namespace std;

int main() {
	int N, L;
	cin >> N >> L;
	string s;
	cin >> s;
	vector<string> v(N);
	for (int i = 0; i < N; i++) {
		v[i] = s[i];
	}
	sort(v.begin(), v.end());
	string ans = "";
	for (int i = 0; i < N; i++) {
		ans = ans + v[i];
	}
	cout << ans << endl;
	return 0;
}

