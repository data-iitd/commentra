#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	vector<int> a(100000);
	int cnt = 1;
	bool isup;
	bool issame = false;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	if (a[0] < a[1])
		isup = true;
	else if (a[0] > a[1])
		isup = false;
	else
		issame = true;
	for (int i = 1; i < n - 1; i++) {
		if (issame) {
			if (a[i] != a[i + 1]) {
				issame = false;
				if (a[i] < a[i + 1])
					isup = true;
				else
					isup = false;
			}
		} else {
			if (isup && a[i] <= a[i + 1]) {
				;
			} else if (!isup && a[i] >= a[i + 1]) {
				;
			} else {
				if (i + 2 < n) {
					if (a[i + 1] < a[i + 2])
						isup = true;
					else if (a[i + 1] > a[i + 2])
						isup = false;
					else
						issame = true;
					cnt++;
				} else {
					cnt++;
					break;
				}
			}
		}
	}
	cout << cnt << endl;
	return 0;
}
