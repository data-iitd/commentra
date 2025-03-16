#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int ns[4];
	cin >> ns[0] >> ns[1] >> ns[2] >> ns[3];

	sort(ns, ns + 4);
	if (ns[0] == 1 && ns[1] == 4 && ns[2] == 7 && ns[3] == 9) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}

	return 0;
}

