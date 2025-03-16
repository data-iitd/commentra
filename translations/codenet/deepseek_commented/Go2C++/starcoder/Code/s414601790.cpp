#include <iostream>
#include <string>

using namespace std;

int main() {
	int n;
	string s;
	cin >> n >> s;

	int max = 0;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'I') {
			cnt++;
		} else {
			cnt--;
		}

		if (cnt > max) {
			max = cnt;
		}
	}

	cout << max << endl;
}

