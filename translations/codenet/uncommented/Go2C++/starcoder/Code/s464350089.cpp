#include <bits/stdc++.h>

using namespace std;

int main() {
	int h, n;
	cin >> h >> n;
	int a = 0;
	for (int i = 0; i < n; i++) {
		a += nextInt();
	}
	if (h > a) {
		cout << "No" << endl;
	} else {
		cout << "Yes" << endl;
	}
}

