#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<char> s(n);
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	vector<int> ns(n);
	for (int i = 0; i < n; i++) {
		switch (s[i]) {
		case 'R':
			ns[i] = 0;
			break;
		case 'G':
			ns[i] = 1;
			break;
		case 'B':
			ns[i] = 2;
			break;
		}
	}

	vector<vector<int>> rgb(n+1);
	rgb[0] = vector<int>(3);
	for (int i = 1; i <= n; i++) {
		rgb[i] = vector<int>(3);
		for (int j = 0; j < 3; j++) {
			rgb[i][j] = rgb[i-1][j];
		}
		rgb[i][ns[i-1]]++;
	}
	int sum = 0;
	for (int i = 0; i < n-2; i++) {
		for (int j = i + 1; j < n-1; j++) {
			if (ns[i] != ns[j]) {
				int tn = 3 - ns[i] - ns[j];
				sum += rgb[n][tn] - rgb[j+1][tn];
				int k = 2*j - i;
				if (k < n && ns[k] == tn) {
					sum--;
				}
			}
		}
	}
	cout << sum << endl;
	return 0;
}

