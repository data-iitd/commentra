#include <iostream>

using namespace std;

int main() {
	int x, a, b;
	cin >> x >> a >> b;
	switch (true) {
		case b-a <= 0:
			cout << "delicious" << endl;
			break;
		case b-a <= x:
			cout << "safe" << endl;
			break;
		default:
			cout << "dangerous" << endl;
			break;
	}
}

