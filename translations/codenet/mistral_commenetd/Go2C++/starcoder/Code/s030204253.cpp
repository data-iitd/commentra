#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<double> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i + 1 < n; i++) {
		sort(a.begin(), a.end());
	}
	vector<double> na;
	for (int j = 2; j < a.size(); j++) {
		na.push_back(a[j]);
	}
	na.push_back((a[0] + a[1]) / 2);
	a = na;
	cout << a[0] << endl;
}

