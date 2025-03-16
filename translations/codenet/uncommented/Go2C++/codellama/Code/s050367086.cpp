
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct MP {
	string s;
	vector<int> table;

	void init(string s) {
		this->s = s;
		int n = s.size();
		vector<int> table(n+1, -1);
		int j = -1;
		for (int i = 0; i < n; i++) {
			for (j >= 0 && s[i] != s[j]) {
				j = table[j];
			}
			j++;
			table[i+1] = j;
		}
		this->table = table;
	}
};

int root(int i, vector<int> uni) {
	if (i == uni[i]) {
		return i;
	}

	uni[i] = root(uni[i], uni);
	return uni[i];
}

int main() {
	string s, t;
	cin >> s >> t;

	int ns = s.size();
	int nt = t.size();
	vector<string> ss((nt-1)/ns+1, s);

	string sss = ss[0] + ss[0];

	vector<bool> ok(ns, false);

	vector<int> uni(ns);
	MP mp;
	mp.init(t);
	int m = 0;
	for (int i = 0; i < ns; i++) {
		uni[i] = i;
	}
	bool o = true;
	for (int i = 0; i < ns; i++) {
		o = true;
		for (m = 0; m < nt; m++) {
			if (t[m] != sss[i+m]) {
				o = false;
				break;
			}
		}
		ok[i] = o;
		if (o) {
			i += nt - mp.table[m];
			m = mp.table[m];
		}
		for (m = 0; m >= 0 && t[m] != sss[i+m]; m = mp.table[m]) {
			i += m - mp.table[m];
		}
		i--;
		m++;
	}

	int ans = 0;
	int r, rr;
	for (int i = 0; i < ns; i++) {
		if (ok[i] == false) {
			continue;
		}
		if (ok[(i+nt)%ns] == false) {
			continue;
		}
		r = root(i, uni);
		rr = root((i+nt)%ns, uni);
		if (rr == r) {
			cout << -1 << endl;
			return 0;
		}
		uni[rr] = r;
	}

	vector<int> counter(ns, 0);
	for (int i = 0; i < ns; i++) {
		if (ok[i] == false) {
			continue;
		}
		r = root(i, uni);
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

