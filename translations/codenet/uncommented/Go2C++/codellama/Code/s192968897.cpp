#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
	string s;
	cin >> s;
	int l = s.length();
	string ans = "AC";
	if (s[0] != 'A') {
		ans = "WA";
	}
	int cnt = 0;
	for (int i = 1; i < l; i++) {
		if (isupper(s[i])) {
			if (i == 1 || i == l - 1 || s[i] != 'C') {
				ans = "WA";
			}
			cnt++;
		}
	}
	if (cnt != 1) {
		ans = "WA";
	}
	cout << ans << endl;
	return 0;
}

