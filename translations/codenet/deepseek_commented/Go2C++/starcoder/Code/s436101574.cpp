#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string s, t;
	cin >> s >> t;

	vector<string> ans;
	for (int i = 0; i < s.size() - t.size() + 1; i++) {
		bool f = true;
		string ss = s;
		for (int j = 0; j < t.size(); j++) {
			if (s[i + j]!= t[j] && s[i + j]!= '?') {
				f = false;
				break;
			} else {
				ss[i + j] = t[j];
			}
		}
		if (f) {
			ans.push_back(ss);
		}
	}
	sort(ans.begin(), ans.end());
	if (ans.size() == 0) {
		cout << "UNRESTORABLE" << endl;
	} else {
		cout << ans[0] << endl;
	}
}

