#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	switch (N % 10) {
	case 2:
	case 4:
	case 5:
	case 7:
	case 9:
		cout << "hon" << endl;
		break;
	case 0:
	case 1:
	case 6:
	case 8:
		cout << "pon" << endl;
		break;
	case 3:
		cout << "bon" << endl;
		break;
	}
}

