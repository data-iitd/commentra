#include <iostream>

using namespace std;

int main() {
	int n, k, cnt;

	cin >> n >> k;
	cnt = 0;
	while (n--) {
		int h;

		cin >> h;
		if (h >= k)
			cnt++;
	}
	cout << cnt << endl;
	return 0;
}

