#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> h(n);
	for (int i = 0; i < n; i++) {
		cin >> h[i];
	}
	int a, b;
	map<int, bool> counter;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		if (h[a-1] < h[b-1]) {
			counter[a] = true;
		} else if (h[a-1] > h[b-1]) {
			counter[b] = true;
		} else if (h[a-1] == h[b-1]) {
			counter[a] = true;
			counter[b] = true;
		}
	}
	cout << n - counter.size() << endl;
}

