#include <iostream>
#include <vector>

using namespace std;

int main() {
	int a, b, c, d, e;
	cin >> a >> b >> c >> d >> e;
	vector<int> al = {a, b, c, d, e};
	for (int n = 0; n < al.size(); n++) {
		if (al[n] == 0) {
			cout << n + 1 << endl;
			break;
		}
	}
	return 0;
}

