#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, a, b;
	cin >> n >> a >> b;
	int tap = 0, consent = 1;
	while (consent < b) {
		consent += a - 1;
		tap++;
	}
	cout << tap << endl;
	return 0;
}

