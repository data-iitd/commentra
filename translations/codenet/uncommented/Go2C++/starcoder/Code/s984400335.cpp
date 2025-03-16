#include <iostream>

using namespace std;

int min(int a, int b) {
	if (a < b) {
		return a;
	}
	return b;
}

int main() {
	int n, a, b;
	cin >> n >> a >> b;

	cout << min(n*a, b) << endl;
}

