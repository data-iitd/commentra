#include <iostream>
using namespace std;

int main() {
	int x, a, b;
	cin >> x >> a >> b;
	switch (b-a) {
		case 0:
			cout << "delicious" << endl;
			break;
		case 1:
			cout << "safe" << endl;
			break;
		default:
			cout << "dangerous" << endl;
			break;
	}
	return 0;
}

