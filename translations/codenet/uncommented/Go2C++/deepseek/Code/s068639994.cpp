#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>

using namespace std;

int getInt() {
	int n;
	cin >> n;
	return n;
}

vector<int> getIntSlice(int n) {
	vector<int> is(n);
	for (int i = 0; i < n; ++i) {
		cin >> is[i];
	}
	return is;
}

string getString() {
	string s;
	cin >> s;
	return s;
}

void puts(const string& s) {
	cout << s << endl;
}

void puts(int n) {
	cout << n << endl;
}

void mainFn() {
	int n = getInt();
	vector<int> ls = getIntSlice(n);
	vector<int> lsRev(ls);
	sort(ls.begin(), ls.end());
	sort(lsRev.begin(), lsRev.end(), greater<int>());

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			int p = min(ls[i], ls[j]);
			int q = max(ls[i], ls[j]);
			int x = q - p;
			int y = q + p;

			int l = distance(ls.begin(), lower_bound(ls.begin(), ls.end(), x, greater<int>()));
			int r = n - distance(lsRev.begin(), lower_bound(lsRev.begin(), lsRev.end(), y));

			int sum = r - l;
			if ((i >= l) && (i <= r)) {
				--sum;
			}
			if ((j >= l) && (j <= r)) {
				--sum;
			}
			sum = max(0, sum);
			ans += sum;
		}
	}

	ans /= 3;
	puts(ans);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	mainFn();
	return 0;
}
