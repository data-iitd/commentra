
#include <iostream>
#include <cmath>

using namespace std;

int walkOnMultiplicationTable(int num) {
	int div = 0;

	for (int i = (int)sqrt(num); i > 1; i--) {
		if (num % i == 0) {
			div = i;
			break;
		}
	}

	if (div == 0) {
		return num - 1;
	}

	return div + num/div - 2;
}

int main() {
	int a;
	cin >> a;
	cout << walkOnMultiplicationTable(a) << endl;
	return 0;
}

