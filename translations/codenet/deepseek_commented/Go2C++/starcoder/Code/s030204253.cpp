#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<float> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	while (n > 1) {
		sort(a.begin(), a.end());
		vector<float> na;
		for (int j = 2; j < n; j++) {
			na.push_back(a[j]);
		}
		na.push_back((a[0] + a[1]) / 2);
		a = na;
		n = na.size();
	}
	cout << a[0] << endl;
}

