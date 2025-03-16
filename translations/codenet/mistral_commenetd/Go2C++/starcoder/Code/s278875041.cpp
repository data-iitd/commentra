
#include <bits/stdc++.h>
using namespace std;

int main() {
	string a;
	cin >> a;
	string tmp = a;
	for (int i = 0; i < tmp.length(); i++) {
		if (tmp[i] == '1') {
			tmp[i] = '0';
		}
	}
	string b = tmp;
	for (int i = 0; i < b.length(); i++) {
		if (b[i] == '9') {
			b[i] = '1';
		}
	}
	string ans = b;
	for (int i = 0; i < ans.length(); i++) {
		if (ans[i] == '0') {
			ans[i] = '9';
		}
	}
	cout << ans << endl;
	return 0;
}

