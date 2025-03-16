#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> ar;

	for (int i = 0; i < 3*n; i++) {
		int x;
		cin >> x;
		ar.push_back(x);
	}

	sort(ar.begin(), ar.end());

	int sum = 0;

	for (int i = 0; i < n; i++) {
		sum += ar[3*n-(i+1)*2];
	}

	cout << sum << endl;
}

