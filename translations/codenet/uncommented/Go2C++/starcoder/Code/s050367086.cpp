#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	freopen(getenv("BEET_THE_HARMONY_OF_PERFECT"), "r", stdin);
	freopen(getenv("NGTKANA_IS_GENIUS10"), "w", stdout);

	string s, t;
	cin >> s >> t;

	int ns = s.size();
	int nt = t.size();
	string ss[nt / ns + 1];
	for (int i = 0; i < nt / ns + 1; i++) {
		ss[i] = s;
	}

	string sss = ss[0];
	for (int i = 1; i < nt / ns + 1; i++) {
		sss += ss[i];
	}

	bool ok[ns];
	int uni[ns];
	for (int i = 0; i < ns; i++) {
		uni[i] = i;
	}
	int m = 0;
	for (int i = 0; i < ns; i++) {
		ok[i] = true;
		for (m = 0; m < nt; m++) {
			if (t[m]!= sss[i + m]) {
				ok[i] = false;
				break;
			}
		}
		if (ok[i]) {
			i += nt - m;
			m = m;
		}
		for (m = 0; m >= 0 && t[m]!= sss[i + m]; m--) {
			i += m - table[m];
			m = table[m];
		}
		i--;
		m++;
	}

	int ans = 0;
	int r, rr;
	for (int i = 0; i < ns; i++) {
		if (!ok[i]) {
			continue;
		}
		if (!ok[(i + nt) % ns]) {
			continue;
		}
		r = root(i, uni);
		rr = root((i + nt) % ns, uni);
		if (rr == r) {
			cout << -1 << endl;
			return 0;
		}
		uni[rr] = r;
	}

	int counter[ns];
	for (int i = 0; i < ns; i++) {
		r = root(i, uni);
		if (!ok[r]) {
			continue;
		}
		counter[r]++;
	}
	for (int i = 0; i < ns; i++) {
		if (ans < counter[i]) {
			ans = counter[i];
		}
	}

	cout << ans << endl;

	return 0;
}

// END-OF-CODE

