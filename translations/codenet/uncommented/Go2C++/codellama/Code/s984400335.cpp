#include <iostream>

using namespace std;

int min(int nums, ...) {
	va_list args;
	va_start(args, nums);
	int min = va_arg(args, int);
	for (int i = 1; i < nums; i++) {
		int v = va_arg(args, int);
		if (v < min) {
			min = v;
		}
	}
	va_end(args);
	return min;
}

int main() {
	int n, a, b;
	cin >> n >> a >> b;

	cout << min(n*a, b) << endl;
}

