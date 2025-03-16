
#include <iostream>
using namespace std;

int comp(int x, int a) {
	if (x < a) {
		return 0;
	}
	return 10;
}

int main() {
	int x, a;
	cin >> x >> a;
	cout << comp(x, a) << endl;
	return 0;
}

