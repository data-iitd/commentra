#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n[4];
	cin >> n[0] >> n[1] >> n[2] >> n[3];

	sort(n, n + 4);
	if (n[0] == 1 && n[1] == 4 && n[2] == 7 && n[3] == 9) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
}

