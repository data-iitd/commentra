
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> ar(3*n);
	for (int i = 0; i < 3*n; i++) {
		cin >> ar[i];
	}
	sort(ar.begin(), ar.end());
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += ar[3*n-(i+1)*2];
	}
	cout << sum << endl;
	return 0;
}

