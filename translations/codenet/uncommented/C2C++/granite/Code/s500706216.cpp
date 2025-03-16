
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	vector<int> light(n + 1, 0);
	for (int i = 0; i < n; i++) {
		int r, l;
		r = i - a[i];
		l = i + a[i];
		light[(r < 0? 0 : r)]++;
		light[(l + 1 > n? n + 1 : l + 1)]--;
	}
	for (int i = 1; i <= n; i++) {
		light[i] += light[i - 1];
	}
	for (int i = 0; i < k; i++) {
		vector<int> tmpa = a;
		for (int j = 0; j < n; j++) {
			a[j] = light[j + 1] - light[j - a[j]];
		}
		if (equal(tmpa.begin(), tmpa.end(), a.begin())) {
			break;
		}
	}
	for (int i = 0; i < n; i++) {
		cout << a[i] << (i == n - 1? "\n" : " ");
	}
	return 0;
}

