#include <iostream>

using namespace std;

int main() {
	int a, b, c, d, e;

	cin >> a >> b >> c >> d >> e;

	int al[] = {a, b, c, d, e};

	for (int n = 0; n < 5; n++) {
		if (al[n] == 0) {
			cout << n + 1 << endl;
			break;
		}
	}
}

