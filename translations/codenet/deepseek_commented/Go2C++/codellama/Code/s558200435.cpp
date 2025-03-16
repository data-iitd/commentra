#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n; // 1. Reading the input number of elements (n)
	cin >> n;

	vector<int> a(n); // 2. Reading the elements into a vector (a)
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	vector<int> b; // 3. Creating a vector (b) to store the longest increasing subsequence
	for (int i = 0; i < n; i++) { // 4. Finding the longest increasing subsequence
		int x = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
		if (x == b.size()) {
			b.push_back(a[i]);
		} else {
			b[x] = a[i];
		}
	}

	cout << b.size() << endl; // 5. Outputting the length of the longest increasing subsequence

	return 0;
}

