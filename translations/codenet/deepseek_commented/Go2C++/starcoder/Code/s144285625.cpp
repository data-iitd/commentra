#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	int ar[3*n];
	for (int i = 0; i < 3*n; i++) {
		cin >> ar[i];
	}
	sort(ar, ar+3*n);
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += ar[3*n-(i+1)*2];
	}
	cout << sum << endl;
}

